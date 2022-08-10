PROGRAM = app

all: $(PROGRAM)

app: main.cpp clean
	gcc -o app main.cpp

run: app
	./$(PROGRAM)

clean: app
	rm app -f

updateufw:
	sudo ufw allow 34255/tcp
	sudo ufw deny 34255/tcp