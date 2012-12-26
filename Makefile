CC=g++
CFLAGS=-c -Wall -std=c++0x

vpath %.o obj

all: snake

snake: snake.o level.o game.o gfx.o events.o main.o
	$(CC) -lallegro -o bin/$@ $+

obj/snake.o: snake.cpp snake.h
	$(CC) $(CFLAGS) -o $@ $<
obj/level.o: level.cpp level.h
	$(CC) $(CFLAGS) -o $@ $<
obj/game.o: game.cpp game.h snake.h level.h
	$(CC) $(CFLAGS) -o $@ $<
obj/main.o: main.cpp snake.h
	$(CC) $(CFLAGS) -o $@ $<
obj/gfx.o: gfx.cpp gfx.h
	$(CC) $(CFLAGS) -o $@ $<
obj/events.o: events.cpp events.h
	$(CC) $(CFLAGS) -o $@ $<

tests: tests.o snake.o level.o game.o
	$(CC) -o bin/$@ $+
	bin/$@

obj/tests.o: tests.cpp snake.h level.h game.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf obj/* bin/*