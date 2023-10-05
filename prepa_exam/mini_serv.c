#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdio.h>
#include <sys/types.h>

typedef struct	s_msg {
	char			*msg;
	size_t			length;
	size_t			sent;
	struct s_msg	*next;
}				t_msg;

typedef	struct s_client {
	unsigned int	id;
	int				comSocket;
	char			*bufMsg;
	t_msg			*msgs;
	struct s_client	*next;
}				t_client;

typedef	struct s_serv {
	int			servSocket;
	int			maxSocket;
	t_client	*clients;
	fd_set		readFdSet;
	fd_set		writeFdSet;
}				t_serv;

int		getMaxSocket(t_serv *server);
int 	extract_message(char **buf, char **msg);
char 	*str_join(char *buf, char *add);
int		broadcastMsg(t_serv *server, char *msg, unsigned int idSender);
int		acceptNewClient(t_serv *server);
int		removeClient(t_serv *server, unsigned int idToRemove);
void	exitError(t_serv *server);
int		processReadingClient(t_serv *server, t_client *client);
int		processWritingClient(t_client *client);
void	setFdSet(t_serv *server);
int		addMsgToClient(t_client *client, char *msg);
void	freeClient(t_client *client);

int		getMaxSocket(t_serv *server)
{
	int			max;
	t_client	*client;

	max = server->servSocket;
	client = server->clients;
	while (client)
	{
		if (client->comSocket > max)
			max = client->comSocket;
		client = client->next;
	}
	return (max);
}

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

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int		broadcastMsg(t_serv *server, char *msg, unsigned int idSender)
{
	t_client	*client;

	client = server->clients;
	while (client)
	{
		if (client->id != idSender && addMsgToClient(client, msg))
			return (1);
		client = client->next;
	}
	return (0);
}

int		acceptNewClient(t_serv *server)
{
	t_client			*newClient;
	static unsigned int	id = 0;
	struct sockaddr_in	cli;
	socklen_t 				len;
	char				str[150];

	newClient = calloc(1, sizeof(t_client));
	if (newClient == NULL)
		return (1);
	len = sizeof(cli);
	newClient->id = id;
	id++;
	newClient->comSocket = accept(server->servSocket, (struct sockaddr *)&cli, &len);
	if (newClient->comSocket < 0)
		return (1);
	if (newClient->comSocket > server->maxSocket)
		server->maxSocket = newClient->comSocket;
  	newClient->next = server->clients;
	server->clients = newClient;
	sprintf(str, "server: client %d just arrived\n", newClient->id);
	if (broadcastMsg(server, str, newClient->id))
		return (1);
	return (0);
}

void	freeClient(t_client *client)
{
	t_msg	*msg;
	t_msg	*tmp;

	msg = client->msgs;
	while (msg)
	{
		tmp = msg;
		if (msg->msg)
			free(msg->msg);
		msg = msg->next;
		free(tmp);
	}
	close (client->comSocket);
	free(client->bufMsg);
	free(client);
}

int		removeClient(t_serv *server, unsigned int idToRemove)
{
	t_client	*client;
	t_client	*previous;
	int			clientSocket;
	
	previous = NULL;
	client = server->clients;
	while (client)
	{
		if (client->id == idToRemove)
		{
			if (previous == NULL)
				server->clients = client->next;
			else
				previous->next = client->next;
			FD_CLR(client->comSocket, &(server->readFdSet));
			FD_CLR(client->comSocket, &(server->writeFdSet));
			clientSocket = client->comSocket;
			freeClient(client);
			break;
		}
		else
		{
			previous = client;
			client = client->next;
		}
	}
	if (server->maxSocket == clientSocket)
		server->maxSocket = getMaxSocket(server);
	return (0);
}

void	exitError(t_serv *server)
{
	t_client	*client;
	t_client	*tmp;

	client = server->clients;
	while (client)
	{
		tmp = client;
		freeClient(tmp);
		client = client->next;
	}
	close(server->servSocket);
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	exit(1);
}

int		processReadingClient(t_serv *server, t_client *client)
{
	char	buffer[4096 + 1];
	char	*newBuffer;
	char	*line;
	int 	byteRecv;
	char	str[150];
	int 	testLine;
	
	line = NULL;
	memset(str, 0, 150);
	memset(buffer, 0, 4096 + 1);
	if (buffer == NULL)
		return (1);
	byteRecv = recv(client->comSocket, buffer, 4096, MSG_DONTWAIT);
	if (byteRecv == -1)
		return (1);
	else if (byteRecv == 0)
	{
		sprintf(str, "server: client %d just left\n", client->id);
		if (broadcastMsg(server, str, client->id) || removeClient(server, client->id))
			return (1);
	}
	else
	{
		if (strstr(buffer, "\n") == NULL)
		{
			client->bufMsg = str_join(client->bufMsg, buffer);	
			return (0);
		}
		newBuffer = str_join(client->bufMsg, buffer);
		client->bufMsg = NULL;
		testLine = extract_message(&newBuffer, &line);
		sprintf(str, "client %d: ", client->id);
		while (testLine)
		{
			if (broadcastMsg(server, str, client->id) || broadcastMsg(server, line, client->id))
				return (1);
			free(line);
			line = NULL;
			testLine = extract_message(&newBuffer, &line);
		}
		if (strlen(newBuffer))
		{
			client->bufMsg = calloc(strlen(newBuffer) + 1 , sizeof(char));
			strcpy(client->bufMsg, newBuffer);
		}
		free(newBuffer);
	}
	return (0);
}

int		processWritingClient(t_client *client)
{
	int 	byteSent;
	t_msg	*msg;

	msg = client->msgs;
	if (msg == NULL)
		return (0);
	byteSent = send(client->comSocket, msg->msg + msg->sent, msg->length - msg->sent, MSG_DONTWAIT);
	if (byteSent == -1)
		return (1);
	else
	{
		msg->sent += byteSent;
		if (msg->sent == msg->length)
		{
			client->msgs = msg->next;
			free(msg->msg);
			free(msg);
		}
	}
	return (0);
}

void	setFdSet(t_serv *server)
{
	t_client	*client;

	FD_ZERO(&(server->readFdSet));
	FD_ZERO(&(server->writeFdSet));
	client = server->clients;
	while (client)
	{
		FD_SET(client->comSocket, &(server->writeFdSet));
		client = client->next;
	}
	server->readFdSet = server->writeFdSet;
	FD_SET(server->servSocket, &(server->readFdSet));
}

int		addMsgToClient(t_client *client, char *str)
{
	t_msg	*newMsg;
	t_msg	*msg;
	
	if (str == NULL)
		return (1);
	newMsg = calloc(1, sizeof(t_msg));
	if (newMsg == NULL)
		return (1);
	newMsg->msg = calloc(strlen(str) + 1, sizeof(char));
	if (newMsg->msg == NULL)
		return (1);
	strcpy(newMsg->msg, str);
	newMsg->length = strlen(newMsg->msg);
	if (client->msgs == NULL)
		client->msgs = newMsg;
	else
	{
		msg = client->msgs;
		while (msg->next)
			msg = msg->next;
		msg->next = newMsg;
	}
	return (0);
}

int main(int argc, char ** argv)
{
	t_serv 				server;
	t_client			*client;
	t_client			*next;
	struct sockaddr_in	servaddr;
	int					selectRetVal;

	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		return (1);
	}
	memset(&server, 0, sizeof(t_serv));
	// socket create and verification 
	server.servSocket = socket(AF_INET, SOCK_STREAM, 0); 
	if (server.servSocket == -1)
		exitError(&server);
	server.maxSocket = server.servSocket;
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));
  
	// Binding newly created socket to given IP and verification 
	if ((bind(server.servSocket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		exitError(&server);
	if (listen(server.servSocket, 4096) != 0)
		exitError(&server);
	while (1)
	{
		setFdSet(&server);
		selectRetVal = select(server.maxSocket + 1, &(server.readFdSet), &(server.writeFdSet), NULL, NULL);
		if (selectRetVal == -1)
			exitError(&server);
		if (FD_ISSET(server.servSocket, &(server.readFdSet)) && acceptNewClient(&server))
			exitError(&server);
		client = server.clients;
		while (client)
		{
			next = client->next;
			if (FD_ISSET(client->comSocket, &(server.writeFdSet)) && processWritingClient(client))
				exitError(&server);
			if (FD_ISSET(client->comSocket, &(server.readFdSet)) && processReadingClient(&server, client))
				exitError(&server);
			client = next;
		}
	}
	return (0);
}
