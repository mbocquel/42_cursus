#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdlib.h>
#include <signal.h>
#define BUFFER_SIZE 65000

typedef struct s_message {
	char 				*message;
	int					send;
	int					length;
	struct s_message	*next;
}				t_message;

typedef	struct 	s_client {
	int					id;
	int					comSocket;
	struct sockaddr_in	clientAddr; 
	t_message			*msg;
	struct s_client		*next;
}				t_client;

typedef struct 	s_server {
	int					serverSocket;
	int					maxSocket;
	t_client			*clients;
	fd_set				readFdSet;
	fd_set 				writeFdSet;
	struct sockaddr_in	servAddr;
}				t_server;

int 	extract_message(char **buf, char **msg);
int		addMessageClient(t_client *client, char *str);
int 	broadcastMessage(t_server	*server, char *str, int	idSender);
int		acceptNewClient(t_server *server);
fd_set	fillFdSetClients(t_server *server);
void	freeClient(t_client *client);
void	exit_clean(t_server *server, int returnValue);
void	remove_client(t_server *server, int idClient);
int		processReadingClient(t_server *server, int fd);
int		processWritingClient(t_server *server, int fd);
void 	handlerSignal(int sig);

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

int	addMessageClient(t_client *client, char *str)
{
	t_message	*new_msg;
	t_message	*msg;

	if (str == NULL)
		return (0);
	new_msg = calloc(1, sizeof(t_message));
	if (new_msg == NULL)
		return (1);
	new_msg->length = strlen(str);
	new_msg->message = calloc(new_msg->length + 1, sizeof(char));
	if (new_msg->message == NULL)
		return (1);
	strcpy(new_msg->message, str);
	if (client->msg == NULL)
		client->msg = new_msg;
	else
	{
		msg = client->msg;
		while (msg->next)
			msg = msg->next;
		msg->next = new_msg;
	}
	return (0);
}

int broadcastMessage(t_server	*server, char *str, int	idSender)
{
	t_client	*client = server->clients;

	while (client)
	{
		if (client->id != idSender)
		{
			if (addMessageClient(client, str))
				return (1);
		}
		client = client->next;
	}
	return (0);
}

int	acceptNewClient(t_server *server)
{
	t_client	*new_client;
	static int	id = 0;
	int			len;
	char		buffer[BUFFER_SIZE + 1];

	memset(&buffer, 0, BUFFER_SIZE + 1);
	new_client = calloc(1, sizeof(t_client));
	if (new_client == NULL)
		return (1);
	new_client->id = id;
	len = sizeof(new_client->clientAddr);
	new_client->comSocket = accept(server->serverSocket, (struct sockaddr *)&(new_client->clientAddr), (socklen_t *)&len);
	if (new_client->comSocket < 0)
		return (1);
	id++;
	if (server->clients == NULL)
		server->clients = new_client;
	else
	{
		new_client->next = server->clients;
		server->clients = new_client;
	}
	if (new_client->comSocket > server->maxSocket)
		server->maxSocket = new_client->comSocket;
	sprintf(buffer, "server: client %d just arrived\n", new_client->id);
	if (broadcastMessage(server, buffer, new_client->id))
		return (1);
	return (0);
}

fd_set	fillFdSetClients(t_server *server)
{
	t_client	*client = server->clients;

	fd_set fdSet;
	FD_ZERO(&fdSet);
	while (client)
	{
		FD_SET(client->comSocket, &fdSet);
		client = client->next;
	}
	return (fdSet);
}

void	freeClient(t_client *client)
{
	t_message	*msg;
	t_message	*tmp_msg;

	
	if (client->msg != NULL)
	{
		msg = client->msg;
		while (msg)
		{
			tmp_msg = msg;
			msg = msg->next;
			if (tmp_msg->message)
				free(tmp_msg->message);
			free(tmp_msg);
		}
	}
	close(client->comSocket);
	free(client);
}

void	exit_clean(t_server *server, int returnValue)
{
	t_client	*client;
	t_client	*tmp_client;
	
	if (server->clients != NULL)
	{
		client = server->clients;
		while (client)
		{
			tmp_client = client;
			client = client->next;
			freeClient(tmp_client);
		}
	}
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	close(server->serverSocket);
	exit(returnValue);
}

void	remove_client(t_server *server, int idClient)
{
	t_client	*client;
	t_client	*previous;
	
	previous = NULL;
	client = server->clients;
	while (client)
	{
		if (client->id == idClient)
		{
			if (previous == NULL)
			{
				server->clients = client->next;
				freeClient(client);
			}
			else
			{
				previous->next = client->next;
				freeClient(client);
			}
			return;
		}
		previous = client;
		client = client->next;
	}
}

int	processReadingClient(t_server *server, int fd)
{
	int			byte_read;
	char		*buffer;
	char		str[150];
	t_client 	*client;
	char		*msg_line;

	client = server->clients;
	buffer = calloc((BUFFER_SIZE + 1), sizeof(char));
	while (client)
	{
		if (client->comSocket == fd)
			break;
		client = client->next;
	}
	if (client == NULL)
		return (1);
	byte_read = recv(fd, buffer, BUFFER_SIZE, 0);
	if (byte_read == -1)
		return (1);
	if (byte_read == 0)
	{
		sprintf(buffer, "server: client %d just left\n", client->id);
		if (broadcastMessage(server, buffer, client->id))
			return (1);
		FD_CLR(client->comSocket, &(server->writeFdSet));
		remove_client(server, client->id);
	}
	else
	{
		msg_line = NULL;
		sprintf(str, "client %d: ", client->id);
		int	test_message; 
		test_message = extract_message(&buffer, &msg_line);
		while (test_message > 0)
		{
			broadcastMessage(server, str, client->id);
			broadcastMessage(server, msg_line, client->id);
			free(msg_line);
			test_message = extract_message(&buffer, &msg_line);
		}
		if (test_message == -1)
			return (1);
		if (strlen(buffer))
		{
			broadcastMessage(server, str, client->id);
			broadcastMessage(server, buffer, client->id);
		}
		if (msg_line)
			free(msg_line);
	}
	free(buffer);
	return (0);
}

int	processWritingClient(t_server *server, int fd)
{
	t_client 	*client;
	int			byte_sent;
	t_message	*tmp;

	client = server->clients;
	while (client)
	{
		if (client->comSocket == fd)
			break;
		client = client->next;
	}
	if (client == NULL)
	{
		printf("coucou\n");
		return (1);
	}
	if (client->msg == NULL)
		return (0);
	byte_sent = send(fd, client->msg->message + client->msg->send, client->msg->length - client->msg->send, MSG_DONTWAIT);
	if (byte_sent == -1)
		remove_client(server, client->id);
	client->msg->send += byte_sent;
	if (client->msg->send == client->msg->length)
	{
		tmp = client->msg;
		client->msg = tmp->next;
		if (tmp->message)
			free(tmp->message);
		free(tmp);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_server	server;
	int		retval;

	memset(&server, 0, sizeof(t_server));
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		return (1);
	}
	// socket create and verification 
	server.serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (server.serverSocket == -1)
		exit_clean(&server, 1);
	const int enable = 1;
	if (setsockopt(server.serverSocket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
		exit_clean(&server, 8);
	
	server.maxSocket = server.serverSocket;
	bzero(&(server.servAddr), sizeof(server.servAddr)); 

	// assign IP, PORT 
	server.servAddr.sin_family = AF_INET; 
	server.servAddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	server.servAddr.sin_port = htons(atoi(argv[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(server.serverSocket, (const struct sockaddr *)&(server.servAddr), sizeof(server.servAddr))) != 0)
		exit_clean(&server, 2);
	if (listen(server.serverSocket, 10) != 0)
		exit_clean(&server, 3);
	
	while (1)
	{
		server.readFdSet = fillFdSetClients(&server);
		server.writeFdSet = server.readFdSet;
		FD_SET(server.serverSocket, &(server.readFdSet));
		retval = select(FD_SETSIZE, &(server.readFdSet), &(server.writeFdSet), NULL, NULL);
		if (retval == -1)
			exit_clean(&server, 4);
		else
		{
			for (int fd = 0; fd <= server.maxSocket; fd++)
			{
				if (FD_ISSET(fd, &(server.readFdSet)) && fd == server.serverSocket && acceptNewClient(&server))
					exit_clean(&server, 5);
				else if (FD_ISSET(fd, &(server.readFdSet)) && fd != server.serverSocket && processReadingClient(&server, fd))
					exit_clean(&server, 6);
			}
			for (int fd = 0; fd <= server.maxSocket; fd++)
			{
				if (FD_ISSET(fd, &(server.writeFdSet)) && processWritingClient(&server, fd))
					exit_clean(&server, 7);
			}
		}
	}
	return (0);
}
