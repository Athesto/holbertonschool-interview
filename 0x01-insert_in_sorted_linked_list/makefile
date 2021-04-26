CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -g
SRC=*.c mains/$*-main.c

%:
	rm -rf ./a.out
	$(CC) $(CFLAGS) $(SRC)
	valgrind -q ./a.out
	@echo "--"
	@./a.out | diff - results/$*-main && echo "\033[32mtest passed\033[0m" || echo "\033[31m failed\033[0m"
	@betty-doc *.c *.h 1>/dev/null
	@betty-style *.c *.h
