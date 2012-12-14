CC=g++
CFLAGS=-c -Wall -std=c++0x

vpath %.o obj

all: snake

snake: obj/snake.o obj/main.o
	$(CC) -o bin/$@ $+

obj/snake.o: snake.cpp
	$(CC) $(CFLAGS) -o $@ $+
obj/main.o: main.cpp
	$(CC) $(CFLAGS) -o $@ $+

tests: tests.o snake.o
	$(CC) -o bin/$@ $+

obj/tests.o: tests.cpp
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -rf obj/* bin/*