CFLAGS = -O
CC = g++

all: main.o io.o
	$(CC) $(CFLAGS) -o all main.o io.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

io.o: io.cpp
	$(CC) $(CFLAGS) -c io.cpp

clean:
	rm -f core *.o 