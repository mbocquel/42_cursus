SOURCES =	docker-compose.yml \
			.env \
			backend/.env \
			frontend/.env

all:     $(SOURCES)
		docker-compose -f ./docker-compose.yml up

build:	$(SOURCES)
		docker-compose up --build

down:    $(SOURCES)
		docker-compose -f ./docker-compose.yml down

clean:    $(SOURCES)
		docker-compose -f ./docker-compose.yml down -v

fclean:    clean
		docker system prune -af

re:        fclean all
.PHONY: all re down clean