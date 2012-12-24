CC=g++
CFLAGS=-c -Wall -std=c++0x

vpath %.o obj

all: snake

snake: obj/snake.o obj/main.o
	$(CC) -o bin/$@ $+

obj/snake.o: snake.cpp snake.h
	$(CC) $(CFLAGS) -o $@ $<
obj/level.o: level.cpp level.h
	$(CC) $(CFLAGS) -o $@ $<
obj/main.o: main.cpp snake.h
	$(CC) $(CFLAGS) -o $@ $<

tests: tests.o snake.o level.o
	$(CC) -o bin/$@ $+
	bin/$@

obj/tests.o: tests.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf obj/* bin/*