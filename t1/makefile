CFLAGS = -O
CC = g++

all: main.o graph.o io.o
	$(CC) $(CFLAGS) -o all main.o graph.o io.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

graph.o: graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp

io.o: io.cpp
	$(CC) $(CFLAGS) -c io.cpp

clean:
	rm -f core *.o 