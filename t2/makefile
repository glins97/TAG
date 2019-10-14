CFLAGS = -O
CC = g++

out: main.o
	$(CC) $(CFLAGS) -o out *.o
	./out
	dot -Tsvg resources/path1 -o path1.svg
	dot -Tsvg resources/path2 -o path2.svg
	dot -Tsvg resources/DAG -o DAG.svg
	dot -Tsvg resources/TOP -o TOP.svg

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