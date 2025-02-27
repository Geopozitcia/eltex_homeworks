CC = gcc
CFLAGS = -Wall
LIBRARY = libcalc.a
OBJECTS = add.o sub.o mul.o div.o

all: calculator

calculator: main.o $(LIBRARY)
	$(CC) $(CFLAGS) main.o -L. -lcalc -o calculator

$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

%.o: %.c calc.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(LIBRARY) calculator