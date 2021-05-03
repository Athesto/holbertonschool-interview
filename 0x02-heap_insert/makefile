CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic
SRC=binary_tree_print.c $*-*.c mains/$*-main.c

%:
	rm -rf ./a.out
	$(CC) $(SRC) $(CFLAGS)
	valgrind -q ./a.out
	@betty-style *.c **.c *.h
	@betty-doc *.c **.c *.h 1> /dev/null

