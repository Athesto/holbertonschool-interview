CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -g
SRC=*.c tests/$@-main.c
OUT=a.out

%:
	rm -rf $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	valgrind -q ./$(OUT)

