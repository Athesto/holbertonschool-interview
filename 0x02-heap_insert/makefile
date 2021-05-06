CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic
SRC=binary_tree_print.c $*-*.c mains/$*-main.c

%:
	rm -rf ./a.out
	$(CC) $(SRC) $(CFLAGS)
	@valgrind -q ./a.out
	@./a.out |\
		diff -y --suppress-common-lines - mains/references/$*-main &&\
		echo "\033[32mOK\033[00m" ||\
		echo "\033[31mKO\033[00m"
	@betty-style $(SRC) *.h
	@betty-doc $(SRC) *.h 1> /dev/null

1: SRC=binary_tree_print.c 0-binary_tree_node.c $*-*.c mains/$*-main.c
