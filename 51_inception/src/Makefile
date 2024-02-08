# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 17:12:15 by mbocquel          #+#    #+#              #
#    Updated: 2023/08/01 17:57:04 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = 	srcs/requirements/mariadb/conf/50-server.cnf \
			srcs/requirements/mariadb/tools/mariadb.sh \
			srcs/requirements/mariadb/Dockerfile \
			srcs/requirements/nginx/conf/nginx.conf \
			srcs/requirements/nginx/Dockerfile \
			srcs/requirements/wordpress/conf/www.conf \
			srcs/requirements/wordpress/tools/config_wp.sh \
			srcs/requirements/wordpress/Dockerfile \
			/home/mbocquel/.env \
			srcs/docker-compose.yml

MARIADB_IMG =	$(shell docker images | grep mariadb | grep 1.0 | wc -l)
WP_IMG =		$(shell docker images | grep wordpress | grep 1.0 | wc -l)
NGINX_IMG =		$(shell docker images | grep nginx | grep 1.0 | wc -l)
MARIADB_VOL = 	$(shell docker volume ls | grep srcs_mariadb_vol | wc -l)
WP_VOL = 		$(shell docker volume ls | grep srcs_wordpress_vol | wc -l)

all: 	$(SOURCES) env_file create_repositories
		docker compose -f srcs/docker-compose.yml up -d --pull never

create_repositories:
		@if [ ! -d "/home/mbocquel/data" ]; \
		then \
			mkdir -p /home/mbocquel/data/mariadb; \
			mkdir -p /home/mbocquel/data/wordpress; \
		else \
			echo "Volume repositories are already up";\
		fi; \
		

env_file: /home/mbocquel/.env
		@if [ ! -e "srcs/.env" ]; \
		then \
			cp /home/mbocquel/.env srcs/.env; \
			echo "Env file added !"; \
		fi; \

down:	$(SOURCES) env_file
		docker compose -f srcs/docker-compose.yml down

mariadb_re: down $(SOURCES) create_repositories env_file
			docker rmi mariadb:1.0
			docker compose -f srcs/docker-compose.yml up -d --pull never

wordpress_re: 	down $(SOURCES) create_repositories env_file
				docker rmi wordpress:1.0
				docker compose -f srcs/docker-compose.yml up -d --pull never

nginx_re: 	down $(SOURCES) create_repositories env_file
			docker rmi nginx:1.0
			docker compose -f srcs/docker-compose.yml up -d --pull never

clean:	down
		@if [ $(MARIADB_IMG) = "1" ]; then echo "	Removing Mariadb Image"; docker rmi mariadb:1.0; fi;
		@if [ $(WP_IMG) = "1" ]; then echo "	Removing Wordpress Image"; docker rmi wordpress:1.0; fi;
		@if [ $(NGINX_IMG) = "1" ]; then echo "	Removing NGINX Image"; docker rmi nginx:1.0; fi;
		@if [ $(MARIADB_VOL) = "1" ]; then echo "	Removing Mariadb Volume"; docker volume rm srcs_mariadb_vol; fi;
		@if [ $(WP_VOL) = "1" ]; then echo "	Removing Wordpress Volume"; docker volume rm srcs_wordpress_vol; fi;
		docker system prune -af

fclean:	clean
		sudo rm -rf /home/mbocquel/data

re:		fclean all

.PHONY: all re down clean