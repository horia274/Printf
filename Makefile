CC = gcc
CFLAGS = -Wall -Wextra -g

.PHONY: all clean run build

all: main run

main: main.o my_printf.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $^ -o $@

my_printf.o: my_printf.c my_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./main

clean:
	rm -rf main main.o my_printf.o

