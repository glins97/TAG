CFLAGS = -O
CC = g++

out: main.o 
	$(CC) $(CFLAGS) -o out *.o
	./out

main.o: io.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

school.o: src/school.cpp
	$(CC) $(CFLAGS) -c src/school.cpp

teacher.o: src/teacher.cpp
	$(CC) $(CFLAGS) -c src/teacher.cpp

io.o: teacher.o school.o src/io.cpp
	$(CC) $(CFLAGS) -c src/io.cpp

clean:
	rm -f core *.o 