-- 1 -- Creating new user
-- 2 -- Voir les info de mdp de l'user
-- 3 -- Ajouter un utilisateur a sudo 
-- 4 -- Ajouter un utilisteur a un groupe
-- 5 -- Voir les partitions du disque
-- 6 -- Voir le status de AppArmor
-- 7 -- Voir le status de ssh
-- 8 -- Voir le status de ufw
-- 9 -- Voir les membres du groupe sudo 
-- 10 - Voir les membres du groupe user42
-- 11 - Modifier le sudoers
-- 12 - Modifier la politique d'expiration des mots de pass
-- 13 - Modifier les regles de complexite du mot de passe
-- 14 - Voir les trucs prevu pour cron
-- 15 - Modifier le hostname de la machine


-- 1 -- Creating new user
sudo adduser maxence
-- 2 -- Voir les info de mdp de l'user
chage -l maxence
-- 3 -- Ajouter un utilisateur a sudo 
sudo adduser maxence sudo
-- 4 -- Ajouter un utilisteur a un groupe
sudo adduser maxence user42
-- 5 -- Voir les partitions du disque
lsblk
-- 6 -- Voir le status de AppArmor
systemctl status AppArmor
-- 7 -- Voir le status de ssh
systemctl status ssh
-- 8 -- Voir le status de ufw
systemctl status ufw
-- 9 -- Voir les membres du groupe sudo 
sudo getent group sudo
-- 10 - Voir les membres du groupe user42
getent group user42
-- 11 - Modifier le sudoers
sudo visudo ou sudo nano /etc/sudoers
puis sudo nano /etc/sudoers.d/sudoconfig
-- 12 - Modifier la politique d'expiration des mots de pass
sudo nano /etc/login.defs
-- 13 - Modifier les regles de complexite du mot de passe
sudo nano /etc/pam.d/common-password
-- 14 - Voir les trucs prevu pour cron
sudo crontab -l
-- 15 - Editer les taches de cron tab
sudo contab -e
-- 15 - Modifier le hostname de la machine
sudo nano /etc/hostname