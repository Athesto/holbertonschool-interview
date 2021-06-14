CFLAGS=-g -Wall -Wextra -Werror -pedantic -std=gnu90
CC=gcc
SRC=*.c tests/0-main.c
OUT=a.out

build:
	@rm -rf $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@betty-doc $(SRC) 1> /dev/null
	@betty-style $(SRC)
	@#$(MAKE) --no-print-directory run

run:
	valgrind -q ./$(OUT) 101

