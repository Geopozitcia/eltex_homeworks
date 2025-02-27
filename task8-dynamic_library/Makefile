CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -ldl
LIBRARY = libcalc.so
OBJECTS = add.o sub.o mul.o div.o

all: calculator

calculator: main.o $(LIBRARY)
	$(CC) $(CFLAGS) main.o -o calculator $(LDFLAGS)

$(LIBRARY): $(OBJECTS)
	$(CC) -shared -o $(LIBRARY) $(OBJECTS)

%.o: %.c calc.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(LIBRARY) calculator