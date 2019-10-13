CFLAGS = -O
CC = g++

out: main.o
	$(CC) $(CFLAGS) -o out *.o
	./out

main.o: graph.o io.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

graph.o: course.o graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp 

io.o: io.cpp
	$(CC) $(CFLAGS) -c io.cpp

course.o: course.cpp
	$(CC) $(CFLAGS) -c course.cpp

clean:
	rm -f out *.o 