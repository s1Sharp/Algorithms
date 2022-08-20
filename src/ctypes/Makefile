PROGRAM = app
CFILE = lib.c
SHAREDLIB = lib.so

all: $(PROGRAM)

app: sharedlib run clean

sharedlib: $(CFILE)
	gcc -fPIC -shared -o $(SHAREDLIB) $(CFILE)

clean:
	rm -rf *.so

run: sharedlib
	python3 main.py
