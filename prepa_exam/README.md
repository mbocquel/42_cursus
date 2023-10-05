# Final Exam 42

## Objectif
Code un petit server en C qui permet a des clients de s'envoyer des messages comme dans un chat. 

## Difficultes 
Le serveur doit etre non bloquant via l'utilisation de Select. Il faut faire en sorte de pouvoir gerer des messages tres tres long. 
Il ne faut pas de memory leak ni de FD open. 

La moulinette test la connexion de plusieurs milliers de clients de maniere tres rapide. Si notre code met trop de temps pour accept ces clients, une erreur sera envoye aux clients qui ne peuvent pas se connecter et ca sera un fail. 
Il faut donc optimiser les etapes apres le Select pour rapidement realiser les traitements necessaires (Accepter un nouveau client, lire un message, envoyer un message.)

## Ma solution

### int extract_message(char **buf, char **msg);

Fonction fournie par le sujet, un peu complique a comprendre, mais permet en l'appelant plusieurs fois de recuperer chaque lignes d'une chaine de characteres. 

### char *str_join(char *buf, char *add);

Fonction fournie par le sujet. Attention a la fin de la fonction buf est free. 

### int getMaxSocket(t_serv *server);

Permet de recuperer la valeur du socket le plus grand parmi le socket de communication du serveur, et ceux des clients. 

### int broadcastMsg(t_serv *server, char *msg, unsigned int idSender);

Permet de diffuser a tous les clients sauf celui avec id == idSender, le message "msg"

### int acceptNewClient(t_serv *server);

Permet d'accepter un nouveau client, de le creer dans la liste de clients et de lui affecter un socket de communication.

### int removeClient(t_serv *server, unsigned int idToRemove);

Permet de supprimer le client avec id == idToRemove de la liste des clients.

### void exitError(t_serv *server);

Permet de sortir proprement du programme (en liberant la memoire et en fermant les FD) et en affichant "Fatal Error\n" sur la sortie d'erreur. 

### int processReadingClient(t_serv *server, t_client *client);

Fonction qui permet de lire et stocker les donnees envoyes par un client. 

### int processWritingClient(t_client *client);

Fonction qui permet d'envoyer les messages a un client. 

### void setFdSet(t_serv *server);

Fonction qui permet d'initialiser les fd_set du server a chaque tour de boucle. 

### int addMsgToClient(t_client *client, char *msg);

Fonction qui ajoute le message msg dans le liste des messages a envoyer d'un client.

### void freeClient(t_client *client);

Fonction qui libere proprement la memoire d'un client. 