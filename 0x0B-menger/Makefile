CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic  -std=gnu90
SRC=0-menger.c tests/0-main.c

build:
	rm -rf a.out
	$(CC) $(CFLAGS) $(SRC) -lm
	betty-doc $(SRC) 1>/dev/null
	betty-style $(SRC)
	valgrind -q ./a.out 2
