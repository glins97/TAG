CFLAGS = -O
CC = g++

out: main
	$(CC) $(CFLAGS) -o out *.o
	./out

main: graphs.o io main.cpp
	$(CC) $(CFLAGS) -c main.cpp

graphs.o: graphs/archs/*.cpp graphs/items/*.cpp
	$(CC) $(CFLAGS) -c graphs/archs/*.cpp graphs/items/*.cpp 

io: io.cpp
	$(CC) $(CFLAGS) -c io.cpp

clean:
	rm -f out *.o 