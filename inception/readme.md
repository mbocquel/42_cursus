# Inception

## Difference entre image et container :
Un container c'est le running environnement of an image. A container contient un File System virtuel, un environnement configs et une image d'application. 

## Commandes 
- **sudo docker pull image_name**
	- Recupere l'image sur le repository par default (docker hub) 
	- On peut  aussi ajouter la version que l'on veut. Par default c'est la derniere.
- **sudo docker run image**
	- va demarer un container avec l'image qu'on lui donne. 
	- par default ca run le container dans le terminal qu'on a lance et si on arrete le processus avec un Ctrl C ca va arreter le container. 
- **sudo docker run -d image**
	- Demmare le container en mode detatch.
	- Renvoie l'id du container creer.
- **sudo docker run -d --name name_of_the_container image**
	- permet de donner un nom personalise au container
- **sudo docker stop id_du_container**
	- stop le container. 
- **sudo docker start id_du_container**
	- redemmare le container. 
- **sudo docker ps**
	- permet d'avoir la liste des containers qui run. 
- **sudo docker ps -a** 
	- Permet d'avoir la liste des containers qui sont running et non running. 
- **sudo docker run -d image_non_presente_sur_la_machine**
	- telecharge l'image et run le container. 
- **sudo docker images**
	- Donne la liste des images docker dispo sur l'ordi.
- **sudo docker rm $(sudo docker ps -aq)**
	- Pour supprimer les containers. 


## Container port vs Host Port
il faut faire un binding sudo docker rm $(sudo docker ps -aq)

**Pour ca il faut faire :**

- sudo docker run -p PORT_OF_THE_HOST:PORT_CONTAINER image_name (exemple sudo docker run -p 6000:6379 redis)

Ce n'est pas possible de run deux containers avec le meme Host port car c'est deja utilise. 

## Debub les containers
Si on sait pas ce qui se passe dans un container, on peut voir les logs que le container produit : 

**sudo docker logs ID_DU_CONTAINER** ou **sudo docker logs NAME_DU_CONTAINER**


On peut aussi acceder au terminal d'un container : 
**sudo docker exec -it COTAINER_ID /bin/bash** et on rentre dedans en utilisant bash. 

on peut aussi utiliser le name du container plutot que le ID. 

## Difference entre docker run et start
Run permet de creer un nouveau container a partir d'une image. On peut lui dire les attribus, les ports etc. 

Une fois que le container est creer, on peut l'arreter et le redemarer avec docker start, ca va reprendre les attribus du container qui ont ete fais avec la commande docker run. 


## Docker network
docker creates son docker network isole dans lequels les containers sont ensemble et peuvent parler ensemble juste avec le container name. 

Les applications qui run en dehors du network peuvent se connecter avec les containers via le lien de port de host. 

**sudo docker network ls** : Permet de voir la liste des docker network qui sont en place. 
On peut creer un network qui va servir pour une application par exemple :
**sudo docker network create my_network_name**.

On peut indiquer le network au moment de docker run. 

avec l'option --net net_work_name

Pour donner des variables d'environnement a la creation du container on peut utiliser sudo docket run -e VARIABLE_ENV="VARIABLE"



## Docker Compose 
Permet d'automatiser les actions de creation des containers. 

pour ca il faut dans le fichier :

```
version:'3'
services:
	mongodb:
	image: mongo
	ports:
	- 27017:27017
	environment:
	- MONGO_USERNAME=admin
```
ce fichier doker-compose.yaml est equivalent aux lignes de commandes suivantes : 

```
docker run -d \
--name mongodb \
-p 27017:27017 \
-e MONGO_USERNAME=admin
mongo
```

C'est plus facile de modifier le file. 
docker-compose va se charger de creer un network lui meme. Pas besoin de specifier le network. \

pour ensuite lancer le projet avec un fichier docker compose
**sudo docker-compose -f fichier_compose.yaml up**

docker compose va creer un network par default. 

**ATTENTION** Quand on restart un container, toutes les modifs qu'on a fait sont effaces. 

Avec docker compose on peut stoper les containers d'un .yaml en une fois. 
```sudo docker compose -f file.yaml down```

ca supprime aussi le netwrok. 


## Docker file

on va utiliser un docker file pour creer une image docker avec notre application. 

un Docker file c'est la suite d'instruction pour creer une image. 

Syntac du docker file :

```
FROM image //ici on peut dire genre debian. 
ENV	MONGO_DB_USER=admin \
	MONGO_PWD=password // peut etre fait en dehors du docker file.

RUN mkdir -p /home/app (on peut lancer toutes les commandes que l'on veut dans le container avec RUN. ici le fichoer est creer dans le container et pas dans le host. )

COPY . /home/app (ici ca copy les fichier du dossier current du host vers le dossier app du container)

CMD ["node", "server.js"]

```

CMD est l'entry point. on peut en avoir que un, alors quon peut avoir plusieurs RUN. 

le dockerfile est toujours appele Dockerfile. 

## Creer une image avec un Dockerfile
il faut utiliser 
```sudo docker build -t my-app:1.0 .``` le dernier . c'est pour dire la localisation du Dockerfile. 


## Docker Volumes
Utiliser pour de la persistance de donnees. 

Dans le cas ou l'on arrete un container, quand on le redemare, les modifications, par exemple dans la base de donnee, sont effacees et on redemare a zero. 


Pour creer un docker volume (qui permet de resoudre se probleme) il y a plusieurs solutions :
- sudo docker run -v /home/mount/data:/var/lib/mysql/data

(la permiere partie avant le : c'est le dossier du host qui est lie au dossier du container.)
si on met pas le volume du host, docker le fait seul et cree un volume dans le dossier docker du host. 

on peut aussi referencer le volume host par name. -v name:/var/lib/mysql/data

On peut aussi utiliser docker compose, avec :

volumes:
- db-data:/var/lib/mysql/data

et a la fin, au meme niveau d'indentation que services, on met 
volumes:
	db-data

Permet de monter le meme volume sur plusieurs containers, si jamais lews containers on besoin de partager des volumes. 
