CFLAGS = -g -Wall

run: sort.o parser.o
	g++ -o $@ sort.o parser.o $(CFLAGS)

sort.o: sort.cpp parser.h
	g++ -c sort.cpp $(CFLAGS)

parser.o: parser.cpp parser.h
	g++ -c parser.cpp $(CFLAGS)

clean:
	rm -f sort *.o
