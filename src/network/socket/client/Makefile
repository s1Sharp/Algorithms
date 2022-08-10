PROGRAM = app

all: $(PROGRAM)

app: main.cpp clean
	gcc -o app main.cpp

run: app
	./$(PROGRAM)

clean: app
	rm app -f