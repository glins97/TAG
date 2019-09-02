CFLAGS = -O
CC = g++

out: main.o utils.o graph.o io.o
	$(CC) $(CFLAGS) -o out main.o graph.o io.o utils.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

graph.o: graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp

io.o: io.cpp
	$(CC) $(CFLAGS) -c io.cpp

utils.o: utils.cpp
	$(CC) $(CFLAGS) -c utils.cpp

clean:
	rm -f core *.o 