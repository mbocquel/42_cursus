# Final Exam 42

## Objectif
Code un petit serveur en C qui permet à des clients de s'envoyer des messages comme dans un chat. 

## Difficultés 
Le serveur doit être non bloquant via l'utilisation de Select. Il faut faire en sorte de pouvoir gérer des messages très très longs. 
Il ne faut pas de memory leak ni de FD open. 

La moulinette teste la connexion de plusieurs milliers de clients de manière très rapide. Si notre code met trop de temps pour accept ces clients, une erreur sera envoyée aux clients qui ne peuvent pas se connecter et ça sera un FAIL. 
Il faut donc optimiser les étapes après le Select pour rapidement réaliser les traitements nécessaires (Accepter un nouveau client, lire un message, envoyer un message.)

## Ma solution

### int extract_message(char **buf, char **msg);

Fonction fournie par le sujet, un peu compliquée a comprendre, mais permet en l'appelant plusieurs fois de récupérer chaque ligne d'une chaine de caractères. **ATTENTION: "msg" est malloc et il faut le libérer.** 

### char *str_join(char *buf, char *add);

Fonction fournie par le sujet. **ATTENTION: à la fin de la fonction, "buf" est free.** 

### int getMaxSocket(t_serv *server);

Permets de récupérer la valeur du socket le plus grand parmi le socket de communication du serveur, et ceux des clients. 

### int broadcastMsg(t_serv *server, char *msg, unsigned int idSender);

Permet de diffuser a tous les clients sauf celui avec id == idSender, le message "msg"

### int acceptNewClient(t_serv *server);

Permets d'accepter un nouveau client, de le créer dans la liste de clients et de lui affecter un socket de communication.

### int removeClient(t_serv *server, unsigned int idToRemove);

Permet de supprimer le client avec id == idToRemove de la liste des clients.

### void exitError(t_serv *server);

Permets de sortir proprement du programme (en libérant la mémoire et en fermant les FD) et en affichant "Fatal Error\n" sur la sortie d'erreur. 

### int processReadingClient(t_serv *server, t_client *client);

Fonction qui permet de lire et stocker les donnees envoyes par un client. 

### int processWritingClient(t_client *client);

Fonction qui permet d'envoyer les messages à un client. 

### void setFdSet(t_serv *server);

Fonction qui permet d'initialiser les fd_set du serveur à chaque tour de boucle. 

### int addMsgToClient(t_client *client, char *msg);

Fonction qui ajoute le message msg dans la liste des messages à envoyer d'un client.

### void freeClient(t_client *client);

Fonction qui libère proprement la mémoire d'un client. 

### int main(int argc, char **argv)

La structure du main est copiée du main.c donné par le sujet. À la suite du Select, on ne teste que les Sockets qui sont utilisées par le serveur et les clients pour réduire les actions inutiles. 
Attention quand on teste les clients, la fonction processReadingClient peut entrainer la suppression (et donc la libération) du client, il faut donc sauvegarder le pointeur vers le prochain client (next = client->next;) avant de lancer cette fonction. C'est aussi pour cela que l'on tente d'abord d'écriture au client avant de tenter la lecture. 