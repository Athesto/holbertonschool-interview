# 0x0A. 2048 (single line)
 > Single line for the game 2048

## How to Install

```console
$ git clone https://github.com/Athesto/holbertonschool-interview.git
Cloning into 'holbertonschool-interview'...
...
$ cd holbertonschool-interview/0x0A-slide_line
$ make 0
rm -rf a.out
gcc -Wall -Wextra -Werror -pedantic -g -std=gnu90 *.c tests/0-main.c
betty-doc *.c *.h 1>/dev/null
betty-style *.c *.h
$

```

if you don't have betty's linting clone the repo and go into de projects
as the previous step and compile it as it's described below

```console
$ gcc -Wall -Wextra -Werror -pedantic -g -std=gnu90 *.c tests/0-main.c
```

## How to run
 - Run the script (in the example is `./a.out`)
 - The first argument is the move ment Left or right (`L`/`R`)
 - The second and more is the array (`2 2 4 8`)

```console
$ ./a.out L 0 0 2 2 4
Line: 0, 0, 2, 2, 4
Slide to the left
Line: 4, 4, 0, 0, 0
```

## Author
 - Gustavo Mejía

