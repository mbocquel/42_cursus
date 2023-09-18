# born2beroot

## Concepts

### Unix

**https://fr.wikipedia.org/wiki/Unix**  

#### Origine / Definition

Cree initialement par Bell Labs (dans les annes 70) puis concept repris par AT&T : **systeme d'exploitation multitache et multiutilisateur** qui repose principalement sur un **interpreteur** (aussi appele **un shell Unix** comme *Bourne Shell - sh, Bourne Again Shell - bash, zsh*...) et plusieurs composants utilisables avec des mecanismes de **pipes** et de **redirections**, et des **appels en ligne de commande.**

https://fr.wikipedia.org/wiki/Shell_Unix  
https://fr.wikipedia.org/wiki/Commandes_Unix

Une particularite d'Unix est de considerer de nombreux objets comme des fichiers : les peripheriques d'entree-sortie par exemple.

#### Declinaisons

Ce systeme est celui sur lequel se basent presques tous les systemes d'exploitation PC ou mobile actuels (sauf les Windows NT), appeles **"systemes UNIX"**.

Les principales familles de systemes UNIX sont :
- BSD (Berkeley Software Distribution)
- **GNU** ou aussi appele **GNU/Linux**
- Autres systemes que GNU fonctionnant sur **noyau Linux : Android, macOS**, Solaris, Atari System 5...

#### Developpements paralleles / complementaires

Le **langage C** (auparavant appele *New B*) a ete cree pour la creation de l'UNIX dans le debut des annees 70.

En 1988, le standard de normes **POSIX** a ete cree pour standardiser les interfaces de programmation de logiciels destines a fonctionner sur les variantes d'UNIX. 

Aujourdhui, la marque deposee UNIX est possedee par l'*OpenGroup*, et pour utiliser cette marque pour un OS, il faut qu'il soit conforme a la *Single Unix Specification*.

## Linux

**https://fr.wikipedia.org/wiki/Linux**

### Origine / Definition

Linux, cree par Linus Torvalds en 1991, n'est pas un systeme d'exploitation. 

*Souvent quand on parle de 'Linux', c'est un abus de langage pour designer plutot soit le systeme d'exploitation GNU (appele couramment GNU/Linux car fonctionnant sur noyau Linux), soit une distribution Linux.*

Linux est un **noyau** de systeme d'exploitation. On voit d'ailleurs par leurs noms les *aspects complementaires du kernel (noyau) et du shell (enveloppe).*

### Noyau de systeme d'exploitation

Certains (la grande majorite: GNU/Linux, Windows, Mac OS X) systemes d'exploitation ont leur memoire vive physique partitionnee virtuellement en 2 espaces:
- **l'espace noyau**
- **l'espace utilisateur**

Sur ces systemes, **le noyau est un logiciel qui est une portion du systeme d'exploitation**, gerant notamment:
- la gestion des differents **logiciels** (processus / taches)
- la gestion du **materiel** - entrees / sorties (memoire, processeur, peripherique, stockage...)
- **la communication entre les logiciels et le materiel**

Un noyau peut comporter un perimetre plus important que celui cite plus haut (notamment pour les noyaux monolithiques).

La communication entre l'espace utilisateur et l'espace noyau (= quand une fonction appelee par un programme de l'espace utilisateur demande un traitement et une execution interne au noyau puis renvoie le resultat dans le programme utilisateur) se fait par des **appels systemes**.

**Les appels systemes sont tres lourds en nombre d'instructions primitives** compares a des appels de fonctions classiques, c'est pourquoi certaines fonctions utilises souvent et de maniere intenses sont deplacees dans l'espace noyau pour plus d'efficacite (exemple: pilotes de peripheriques tres sollicites comme celui du disque dur).

On peut resumer les differentes architectures de noyaux en 2 grandes categories contraires: les noyaux monolithiques VS les micro-noyaux. 

Un **noyau monolithique (non-modulaire)** regroupe l'ensemble des fonctions du systeme et des pilotes dans son noyau sous la forme d'un seul bloc de code compilable en un seul binaire. Les premieres versions de Linux etaient a noyau monolithique non-modulaire.

A l'inverse un **systeme a micro-noyau** fait porter le minimum du perimetre au noyau appele cette fois micro-noyau, et beaucoup de fonctionnalites systeme de l'OS sont deplacees hors du noyau, en espace utilisateur, pour former le **micro-noyau enrichi**. 

**Dans la pratique, un compromis est souvent trouve entre ces 2 architectures.**   
Ainsi les versions recentes de Linux sont a **noyau monolithique modulaire:** seules les parties fondamentales du systeme sont regroupees dans un code unique, et les autres fonctions (comme les pilotes materiels) sont regroupees/separees dans differents codes/binaires, permettant une flexibilite de configuration.  
Et Windows et Mac OS sont plutot des architectures dites "**hybrides**", proches d'une architecture a micro-noyau enrichi mais en integrant tout de meme certaines choses supplementaires dans le micro-noyau pour des raisons de performances d'appels systeme. 

https://fr.wikipedia.org/wiki/Noyau_de_syst%C3%A8me_d%27exploitation

### Distributions Linux

Une distribution est une sorte de declinaison d'OS prete a l'emploi (avec un certains nombres de logiciels -libres ou non- integres, des elements de configuration...) tout en laissant la possibilite de changer certains elements comme le noyau par exemple.

https://fr.wikipedia.org/wiki/Distribution_Linux

### Debian

Debian est une des distributions Linux historiques (mais il existe aussi des distributions Debian basees sur d'autres noyaux que Linux), **entierement libre** (c'est plus precisement une distribution GNU/Linux), et sur laquelle se basent d'autres distributions populaires comme Ubuntu.

Avantages:
- tres adapte pour des serveurs, mais est aussi bien adapte pour des PCs ou telephones
- tres bonne securite par transparence du code source

https://fr.wikipedia.org/wiki/GNU
https://fr.wikipedia.org/wiki/Debian

Debian, comme d'autres systemes bases sur GNU, gere ses programmes sous forme de paquets (archives contenant tout ce dont le logiciel a besoin pour fonctionner), installables grace a un gestionnaire de paquets.

Pour Debian, les paquets sont au format `.deb`, ce sont des **archives**.

## Virtualisation

**https://fr.wikipedia.org/wiki/Virtualisation**

### Definition

La virtualisation consiste a executer sur une machine hote **dans un environnement isole** des systemes d'exploitation (**virtualisation systeme**) ou des applications (virtualisation applicative).

La virtualisation peut entre autres servir pour:
- **optimiser la charge d'utilisation** d'un parc de machines physiques / **economie par mutualisation** (une machine pouvant heberger plusieurs machines virtuelles en fonction de leur charge, utile pour les serveurs, aui consomment presque la meme chose si utilises a 90% ou a 10%)
- installation, deploiement et migration facilites d'une machine physique a une autre dans un **contexte de mise en production**
- **securisation**: tests critiques / cassage sans incidence sur le systeme d'exploitation hote
- flexibilite et **scalabilite**
- allocation dynamique de puissance de calcul

Contraintes:
- performances amoindries par rapport a un mode natif
- si la machine hote tombe en panne, toutes ses machines virtuelles aussi (mais de la redondance est facilement implementable)
- mise en oeuvre complexe au depart

### Types de virtualisation

- **Isolateur / conteneur**: avec Linux uniquement, un type de virtualisation qui n'en est est pas completement une car les conteneurs ne sont pas entierement isoles. Exemple: **Docker**
- **Hyperviseur de type 2**: logiciel qui virtualise et/ou emule le materiel pour les OS invites, de sorte que ces OS croient communiquer directement avec le materiel. Exemple: **Oracle Virtualbox**
- **Hyperviseur de type 1**: comme un noyau systeme tres leger et optimise pour gerer les acces des noyaux des OS invites a l'architecture materielle. Ex: Microsoft Hyper-V Server, KVM.


## Creer son Serveur Debian avec Virtualbox

https://fr.wikipedia.org/wiki/Oracle_VM_VirtualBox

- creer une nouvelle machine virtuelle et allouer 1Go de RAM. Pour info, commande pour connaitre la memoire totale de la machine: `grep MemTotal /proc/meminfo`.
- Creation du Disque Dur Virtuel:
	- Type de hard disk file: image VDI (le format d'images par defaut de Virtualbox). Une image VDI est le fichier cree par Virtualbox quand on cree une machine virtuelle (https://www.eugenetoons.fr/utiliser-un-fichier-vdi-dans-virtualbox/). **Une image systeme est une archive qui stocke l'etat entier d'un ordinateur** (a des fins de duplication ou de backup). **Utiliser directement une image VDI prete a l'emploi permet de s'affranchir de certaines etapes prealables a l'installation de l'OS invite.**
	- **Taille fixe**: elle ne pourra plus etre augmentee, mais a l'avantage de fournir des performances proches d'un disque natif, la ou les performances sont degradees au fur et a mesure de l'augmentation de l'espace d'un disque dynamiquement alloue (car des operations d'augmentation de capacite precedent les operations d'ecriture). La creation d'un disque de taille fixe estp lus longue mais le temps perdu au depart est gagne a l'utilisation (https://superuser.com/questions/381351/fixed-size-disk-vs-dynamically-allocated-is-there-a-performance-difference-on-a)
	- choisir la taille fixe a allouer (depend si l'on fait les bonus du sujet ou pas) et confirmer l'emplacement d'enregistrement de l'image vdi.

- VM eteinte, **changer le Graphics Controller de VMSVGA vers VBoxVGA** dans Settings/Display pour eviter des messages d'erreur (sans gravite) au demarrage de l'OS a cause d'un bug de VMSVGA: https://www.virtualbox.org/ticket/19168#comment:4
- aller chercher **l'image iso "netinst" pour PC 64 bits**, telechargee via https://www.debian.org/distrib/. 
- **Monter l'image VDI dans Optical Disk pour booter sur l'installeur Debian:**  

	![capture](img/optical_disk.png)
- Lancer la machine

### Installation de Debian

https://www.debian.org/releases/stable/s390x/ch06s03.fr.html

- Install Debian
- choisir la lange, la localisation, la locale, le type de clavier...
- donner un hostname a la machine: "acostes42"
- donner un nom de domaine: laisser vide
- creer le mot de passe root, un utilisateur principal (acostes) et definir son mot de passe
- pour faire les bonus, passer a un setup manuel des partitions

### Strategie de partitionnement

https://www.debian.org/releases/stable/s390x/apcs01.fr.html  
https://www.debian.org/releases/stable/s390x/apcs02.fr.html

![arborescence de fichiers](img/folder_architecture.png)

Sans partitionnement, tous les dossiers ci-dessus sont places dans le dossier racine `/` (a ne pas confondre avec `root`).
**Un partitionnement permet plus de securite** (si une partition est endommagee/corropmupe/surchargee de contenu, les autres ne le sont pas forcement).

**Le seul inconvenient est qu'il peut etre difficile de savoir quel espace allouer a l'avance a chaque partition, et repartitionner exige d'ecraser les donnees existantes.**

### LVM

https://fr.wikipedia.org/wiki/Gestion_par_volumes_logiques  
https://unix.stackexchange.com/questions/87300/differences-between-volume-partition-and-drive
https://tldp.org/HOWTO/LVM-HOWTO/whatisvolman.html

Un moyen de gerer le partitionnement de maniere plus flexible en etant moins dependant des limites de chaque disque physique est d'utiliser un **LVM (Logical Volume Manager)**. 

Un LVM permet de **regrouper plusieurs volumes physiques en groupes de volumes VG, qui peuvent ensuite etre subdivises en volumes logiques LV**, equivalents a des pseudos-partitions.

### Obtenir le partitionnement demande dans le sujet

#### Objectif et notations

https://en.wikipedia.org/wiki/Disk_partitioning

Le sujet demande (dans les bonus) d'avoir une structure de partitionnemt comme suit quand on execute la commade `lsblk` ('list block devices' - cf `man lsblk` et https://unix.stackexchange.com/questions/259193/what-is-a-block-device): 

![partitioning](img/goal_partitioning.png)

- `sd<lettre>`: la lettre numerote les differents **disques physiques** (type: 'disk')

	- `sda<chiffre>`: le chiffre numerote la **partition** du disque physique 'a' (type: part)

`sda5_crypt` indique que la partition 5 est **cryptee** (type: 'crypt'): cela permet en cas de vol du materiel de ne pas acceder aux donnes (besoin de connaitre la **key** du proprietaire - dans notre cas via une **passphrase**)

sda5 est divisee en plusieurs **volumes logiques (LV)** dans un **groupe de volumes (VG)** appele 'LVMGroup'.

sda2 est cree automatiquement pour heberger les volumes logiques de sda5, c'est pourquoi il ne contient que tres peu d'espace: 1K - correspondant a 2 blocs de 512 octets - a priori 1 bloc pour l'**Extended Boot Record** (cf https://en.wikipedia.org/wiki/Extended_boot_record) et 1 bloc supplementaire pour en avoir un nombre pair (cf https://tldp.org/LDP/sag/html/partitions.html).
En effet, **pour creer une logical partition ou logical volume, il faut d'abord creer une extended partition** parmi les 4 partitions autorisees pour les contenir (https://help.ubuntu.com/community/HowtoPartition/PartitioningBasics et https://tldp.org/HOWTO/Partition/requirements.html#number).   
Dans notre cas sda2 est une extended partition contenant les blocs des partitions logiques, on le voit en executant la commande `fdisk -l` (cf https://unix.stackexchange.com/questions/71821/mystery-of-a-small-1k-hard-disk-partition-and-is-it-safe-or-malware-on-ubuntu-1).

*Attention: lsblk et VirtualBox raisonnent en termes de taille dedisque en utilisant des GiB, Mib etc, c'est a dire en base 2 (cf. https://en.wikipedia.org/wiki/Byte#Units_based_on_powers_of_2), tandis que l'installeur Debian raisonne en base 10. => 1 GiB = 1.024 * 1.024 * 1.024 GB. Il faut donc realiser la conversion en choisissant les tailles de partition dans l'installeur.*

#### Setup de la partition table lors de l'installation de Debian

- Definir une installation manuelle
- creer une partion primaire sda1, avec systeme de fichiers ext4, et mountpoint /boot (*Pas besoin de definir de bootflag car GRUB va se charger de la gestion du boot.* cf https://en.wikipedia.org/wiki/Boot_flag#:~:text=A%20boot%20flag%20is%20a,Any%20other%20value%20is%20invalid)
- creer un encrypted volume pour le reste de l'espace (le contenu du disque va etre efface avant pour assurer une meilleure securite)
- configurer un LVM pour la partition cryptee
- creer un groupe de volumes qu'on appellera 'LVMGroup' 
- ajouter les LVM un a un en les nommant sans la partie "LVMGroup-" apparaissant dans le resultat de `lsblk`, leur nom sera automatiquement prepend du nom de groupe auquel ils appartiennent
- definir un systeme de fichiers ext4 pour tous les volumes logiques sauf swap, qui doit juste etre definie comme "swap area" dans son use case, et definir leur mountpoint (sauf pour swap)

**Une Swap Area est une portion de disque dur qui peut etre utilisee en cas de depassement de la memoire RAM.** https://web.mit.edu/rhel-doc/5/RHEL-5-manual/Deployment_Guide-en-US/ch-swapspace.html#:~:text=Swap%20space%20in%20Linux%20is,a%20replacement%20for%20more%20RAM.

### Finalisation de l'installation de Debian

- Deselectionner tous les sofwares optionnels pour ne pas les installer
- Installer **GRUB boot loader** sur la partition primaire

### Modifications du partitionnement si besoin

Les commandes de `lvm2` peuvent servir a divers choses comme renommer des VG (`vgrename oldname newname`) et des LV (`lvrename vg oldname newname`). 

![rename](img/lvrename.png)

Pour pouvoir utiliser lvm il faut ajouter /sbin a la variable PATH: 

```
PATH=/sbin:$PATH
```

Pour examiner le resultat on peut utiliser la commande `lsblk` ou bien `fdisk -l`. 

*Note : Pour scroller dans un resultat de terminal dans la VM, il faut installer screen (`apt install screen` en tant que superuser), y ouvrir une session de terminal (`screen`) et utiliser le raccourci clavier de la commande copy (https://www.gnu.org/software/screen/manual/screen.html#Copy)*

### Installation de paquets - APT

https://fr.wikipedia.org/wiki/Advanced_Packaging_Tool
https://en.wikipedia.org/wiki/APT_(software)

Les systemes GNU/Linux (et d'autres) ont leur logiciels geres sous forme de **paquets**: ce sont des archives contenant les fichiers, informations et procedures necessaires a l'installation du logiciel sur un systeme d'exploitation, en s'assurant de la coherence fonctionelle du systeme modifie. 

**Sous Debian et ses derives, les paquets sont des fichiers `.deb`**

Un **gestionnaire de paquets** permet:
- **installation, mise a jour, desinstallation**
- **verification de l'integrite** des paquets
- verification des dependances logicielles
- **resolution de dependances** pour certains (APT en fait partie)

Sous Debian, le gestionnaire **APT (Advanced Packaging Tool)** est present en natif dans le systeme, et la commande `apt` est utilisee pour interagir avec.

APT est un **gestionnaire de haut niveau construit sur la base du logiciel `dpkg`** a la base des gestions de paquets Debian (https://fr.wikipedia.org/wiki/Dpkg).

**Aptitude** est une surcouche encore plus haut niveau qu'APT, qui propose notamment une interface semi-graphique (Text-based User Interface - TUI).

APT a l'avantage d'**automatiquement installer les dependances necessaires a l'installation du logiciel vise.** 

Une autre qualite d'APT est qu'il va chercher ses paquets dans des **depots APT** (qui sont des remote repositories - https://fr.wikipedia.org/wiki/D%C3%A9p%C3%B4t_(informatique) - https://doc.ubuntu-fr.org/depots), qui peuvent etre regulierement mis a jour par les constructuers de logiciels.
Ces depots sont listes dans le fichier de configuration **`/etc/apt/sources.list`** (https://manpages.ubuntu.com/manpages/xenial/man5/sources.list.5.html).    
**=> Contrairement a Windows, pas besoin de telecharger et d'installer nous-meme le logiciel, apt va le chercher dans le depot de sa source!**

APT peut donc aussi facilement verifier dans les depots si des mises a jour de logiciels existent. 

La **commande `apt`** regroupe de maniere simplifiee et mois specialisee des usages des comandes **`apt-get`** et **`apt-cache`** (https://manpages.ubuntu.com/manpages/xenial/man8/apt.8.html).

Commandes usuelles:
https://doc.ubuntu-fr.org/apt-get

```man apt``` => https://manpages.ubuntu.com/manpages/xenial/man8/apt.8.html

- ```apt[-get] update```: rechercher quels packages/dependances sont a jour ou non par rapport a leur depots listes dans le fichier `sources.list`

- ```apt[-get] upgrade```: installe les mises a jour identifiees par `apt update` si cela est possible sans supprimer des paquets ou dependances intalles. En revanche de nouvelles dependances peuventetre installees si cela n'implique pas de suppression / downgrade de packages installes => C'est une upgrade "minimale et safe"

- ```apt[-get] full-upgrade```: comme upgrade mais s'autorise a supprimer des packages si necessaire pour mettre a jour l'ensemble. 

- ```apt[-get] install <package_name>[=<version>]```: installe le package a partir de son depot.

- ```apt[-cache] show <package_name>```: montre un resume des informations sur le package (dependances, taille de telechargement, sources depuis lesquelles le package est disponible, description du contenu...)

- ```apt[-cache] policy <package_name>```: pour voir de quel depot provient un package.

### systemctl

https://www.digitalocean.com/community/tutorials/how-to-use-systemctl-to-manage-systemd-services-and-units-fr

`systemctl`est la commande pour interagir avec **systemd**, un gestionnaire de systemes, et comportant notamment un systeme d'initialisation pour Linux (https://fr.wikipedia.org/wiki/Systemd).

systemd permet notamment de decrire quels **services/daemons** (cf. https://fr.wikipedia.org/wiki/Daemon_(informatique)) sont appeles au demarrage ou bien quelles sont leur dependances.  

Commandes usuelles:

-  `systemctl start <service>[.service]`: demarre un service
- `systemctl stop <service>[.service]`: arrete un service en cours d'execution
- `systemctl enable <service>[.service]`: lance un service au demarrage => cela va creer un lien symbolique du fichier de service du systeme dans le dossier ou systemd cherche les fichiers de demarrage automatique (dans `/etc/systemd/system/<target>.target.wants`, ou ,<target> est la target qui "wants" le service)
- `systemctl disable <service>[.service]`: desactive le demarrage automatique d'un service
- `systemctl status <service>[.service]`: affiche l'etat general d'un service
- `systemctl is-enabled <service>[.service]`: affiche si le service est lance automatiquement au demarrage
- `systemctl cat <service>[.service]`: affiche le fichier de l'unite tel que reconnu par systemd (cf `man 5 systemd.service`)

### AppArmor

AppArmor est un logiciel de securite GNU pour Linux permet d'utiliser le **Mandatory Access Control (MAC)**, en complement du modele de Discretionary Access Control (DAC) implemente sous Unix.

Le controle d'acces obligatoire doit etre utilise quand la politique de securite SI exige que **les decisions de protection ne doivent pas etre prises par le proprietaire des objets concernes, mais doivent lui etre imposees par le systeme.**
https://fr.wikipedia.org/wiki/Contr%C3%B4le_d%27acc%C3%A8s_obligatoire

Au contraire, dans le cas d'un controle d'acces discretionnaire, un utilisateur ayant une certaine autorisation d'acces a un element peut transmettre cette permission (directement ou indirectement) a n'importe qui d'autre. https://fr.wikipedia.org/wiki/Contr%C3%B4le_d%27acc%C3%A8s_discr%C3%A9tionnaire

Pour verifier qu'AppArmor s'execute bien au demarrage:

```
systemctl status apparmor
```

ou 

```
systemctl is-enabled apparmor
```

Pour voir le statut des profils AppArmor: 

```
aa-status
```

Pour plus d'infos sur l'utilisation d'AppArmor:
https://medium.com/information-and-technology/so-what-is-apparmor-64d7ae211ed

### Superuser et su, sudo

**https://documentation.suse.com/sles/15-SP2/html/SLES-all/cha-adm-sudo.html**

**La page du man de sudoers contient toutes les infos et explications necessaires a une bonne configuration de sudo: https://manpages.ubuntu.com/manpages/xenial/en/man5/sudoers.5.html**

La commande `su` permet de se logger en superuser ou 'root', possedant tous les droits d'administration possibles. Comme l'utilisation generalisee d'un tel profil est tres dangereuse, on peut choisir de se mettre en superuser uniquement pour l'execution d'une seule commande, en precedant cette commande de `sudo`. 

Pour cela il faut au prealable installer sudo: `apt install sudo`.

Si l'on s'est logge en superuser avec `su`, pour sortir de ce mode, faire CTRL+D ou taper `exit`.

Pour executer sudo, il faut faire partie des **sudoers**. Les utilisateurs ou groupes peuvent etre ajoutes aux sudoers soit en modifiant directement le fichier `/etc/sudoers`, ou bien en les ajoutant dans un nouveau fichier que l'on cree et place dans `/etc/sudoers.d/.` (cf `less /etc/sudoers.d/README`)  
**L'avantage de creer des nouveaux fichier dont les effets vont s'ajouter au fichier sudoers initial est que si l'on veut faire revenir la configuration sudo a son etat d'origine, il suffit de supprimer ces fichiers, sans alterer le fichier sudoers d'origine.**  

https://www.hostinger.com/tutorials/sudo-and-the-sudoers-file/#:~:text=Sudoers%20File%20Syntax,-You%20can%20open&text=%ADmin%20ALL%3D(ALL)%20ALL,privileges%20to%20run%20any%20command

Exemple de syntaxe de base pour ajouter des droits via un fichier sudoers:

- a un utilisateur: 
	```
	<user> ALL=ALL
	```  
- a un groupe:
	```
	%<group> ALL=ALL
	```
ou le premier ALL veut dire "all hosts" et le deuxieme "for all commands"

Pour plus de details sur la syntaxe des fichiers sudoers, voir https://www.digitalocean.com/community/tutorials/how-to-edit-the-sudoers-file et `man sudoers`, et se rappeler de la regle enoncee par le man de sudoers: 

__*The basic structure of a user specification is “who where = (as_whom) what”.*__ 

**_Note: Une erreur de syntaxe dans un fichier sudoers peut avoir de lourdes consequences. Il est donc preferable d'editer ces fichiers via la commande `sudo visudo` en tant que root, qui integre une verification de lasyntaxe sudo avant l'enregistrement._**

Quand on affiche le contenu du fichier sudoers d'origine, on remarque une ligne: 

```
# Allow members of group sudo to execute any command
%sudo	ALL=(ALL:ALL) ALL
```

**Une maniere plus simple (et plus robuste, car on peut plus facilement retirer les droits a l'utilisateur si besoin) d'accorder tous les droits via sudo a un utilisateur est de l'ajouter au groupe existant 'sudo'** (on peut consulter la liste des users appartenant au groupe sudo en executant `grep sudo /etc/group`, ou verifier a quels groupes appartient l'utilisateur logge via la commande `groups`):

```
usermod -aG <group (ici sudo)> <user>
``` 

ou plus simplement 

```
adduser <user> <group>
```

Pour exclure un utilisateur du group:
```
deluser <user> <group>
```

_Attention: parfois, pour que les changements soient applicables, il faut se relogger: `logout` puis se logger de nouveau_

Pour definir la strict policy exigee par le sujet pour sudo, creer un fichier sudoers (`visudo /etc/sudoers.d/my_sudoers_conf` en tant que root) contenant:

_Pour trouver sur quels parametres on peut jouer dans un fichier de config sudoers, cf `man [5] sudoers` puis rechercher `SUDOERS OPTIONS` (utiliser `/` pour la recherche puis `n` et `SHIFT+n`)_

```
Defaults	passwd_tries=3
Defaults	badpass_message="Bad password. FOCUS PLEASE!"
Defaults	logfile=/var/log/sudo/sudo.log
Defaults	log_input, log_output
Defaults	iolog_dir=/var/log/sudo/
Defaults	iolog_file=%{user}/XXXXXX
Defaults	requiretty
```

Le `logfile` se charge des logs de sudo (indiqunt seulement qui a tente d'utiliser quelle commande avec sudo, et c'est aussi la que sont logges les avertissements de depassement e `passwd_tries`), c'est donc differents des logs d'I/O (voir ci-dessous). *Ces "**sudo logs**" sont optionnels, pas demandes dans le sujet.* 

Les logs d'entree/sortie (I/O) sont geres par les variables `log_input`, `log_output`, `iolog_dir` et `iolog_file`. Cette fois, ils recordent toutes les entrees/sorties des commandes utilisees via sudo. Ils ne produisent pas un seul fichier de log contrairement aux sudo logs, mais un dossier par commande, contenant differents fichiers. Les plus importants ici sont: 
**- `log`: contient le log d'input**
**- `ttyout`: contient le log d'output, doit etre decompresse avec zcat ou zless**

On peut choisir la structuration qu'on veut pour ces logs. Ici j'ai choisi que chaque structure de log d'I/O sera non pas stockee dans le dossier par defaut `/var/log/sudo-io` mais dans le dossier `/var/log/sudo`. 

Ensuite, la structure de chaque log est determinee par `iolog_file` comme suit: `%{user}` permet de rassembler tous les dossiers de log d'actions sudo executees par un utilisateur dans un dossier portant comme nom son login, puis chaque commande loggee de cet utilisateur sera stockee sous la forme d'un sous-dossier cree automatiquement sous la forme d'une chaine de 6 caracteres (mis en place par le `XXXXXX` a la fin de la variable, cf le man de sudoers). *En effet, si le dossier de log d'une commande existe deja, il sera ecrase, donc ne pas ajouter les `XXXXXX` a la fin reviendrait a ne logger que la derniere commande sudo effectuee par chaque utilisateur.*

Chaque sous-dossier contient alors l'architecture de logs citee plus haut (`log`, `log.json`, `stdin`, `stdout`, `stderr`, `ttyin`, `ttyout`...). 

**Un moyen de revoir visuellement en "temps reel" l'execution d'une commande sudo dont les I/O ont ete loggees est d'executer `sudoreplay -d <iolog_dir> <iolog_file du log que l'on veut voir>`.**

*Note: Si on ne se rappelle plus des noms de sous-dossiers produits par iolog_file, on peut auparavant executer la commande `sudoreplay -d <iolog_dir> -l` pour lister les differentes commandes loggees et leurs iolog_files associes.*

*Note2: si jamais on veut securiser plus l'utilisation de sudoreplay afin qu'il ne risque pas de boucler sur lui-meme si on l'utilise via sudo (meme si je n'ai pas reussi a reproduire ce probleme), on peut suivre la procedure permettant de ne pas inclure les commandes sudoreplay dans les logs: https://yojimbosecurity.ninja/sudo-logging-2/)*

**Pour les raisons de securitepoussant a setup requiretty (c'est notamment le fait d'interdire d'acceder programmatiquement a sudo):**
https://stackoverflow.com/questions/67985925/why-would-i-want-to-require-a-tty-for-sudo-whats-the-security-benefit-of-requi

*Autres bonnes/mauvaises pratiques pour sudo: https://www.bsdcan.org/2014/schedule/attachments/283_2014-04-29%20sudo%20tutorial%20-%20bsdcan%202014.pdf*

Derniere modification pour plus de securite (pas demande dans le sujet): interdire aux utilisateurs sudo d'executer la commande `sudo su`. En effet cette commande permet de passer en mode root sans meme rentrer une seule fois le mot de passe du root ! Pour cela, editer le sudoers general: 

```
sudo visudo
```

Puis remplacer la ligne donnant les permissions au groupe sudo par:

```
%sudo	ALL=(ALL:ALL) ALL, !/bin/su
```

### Mettre en place une Password Policy






