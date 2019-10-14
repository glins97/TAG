CFLAGS = -O
CC = g++

out: main.o
	$(CC) $(CFLAGS) -o out *.o
	./out

svgs:
	./out
	dot -Tsvg resources/Path1 -o Path1.svg
	dot -Tsvg resources/Path2 -o Path2.svg
	dot -Tsvg resources/DAG -o DAG.svg
	dot -Tsvg resources/TOP -o TOP.svg

main.o: graph.o io.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

graph.o: course.o graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp 

io.o: utils.o io.cpp
	$(CC) $(CFLAGS) -c io.cpp

utils.o: utils.cpp
	$(CC) $(CFLAGS) -c utils.cpp

course.o: course.cpp
	$(CC) $(CFLAGS) -c course.cpp

clean:
	rm -f *.o 