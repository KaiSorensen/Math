CC = clang
CFLAGS = -Wall -Wextra -std=c99
OBJS = main.o mathtest.o math.o

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c mathtest.h
	$(CC) $(CFLAGS) -c $<

mathtest.o: mathtest.c mathtest.h math.h
	$(CC) $(CFLAGS) -c $<

math.o: math.c math.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f main $(OBJS)
	clear

run: clean all
	./main

valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all ./main

.PHONY: all clean run