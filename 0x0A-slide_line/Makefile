CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -g -std=gnu90
SRC=*.c tests/$*-main.c

%:
	rm -rf a.out
	$(CC) $(CFLAGS) $(SRC)
	betty-doc *.c *.h 1>/dev/null
	betty-style *.c *.h

