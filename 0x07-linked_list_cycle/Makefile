CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic
SRC=*.c tests/0-main.c
OUT=a.out

build:
	@rm -rf $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	valgrind -q ./$(OUT)
	@betty-doc $(SRC) 1>/dev/null
	@betty-style $(SRC)

