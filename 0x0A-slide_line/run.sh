#!/usr/bin/env bash
# make 0 > /dev/null
echo "" > tests/0-log
{
    echo "RIGHT"
    ./a.out R 2 2 2 2 2
    ./a.out R 2 2 0 0
    ./a.out R 2 2 0 0 0 0 0 2 0 0 0 2 0 4
    ./a.out R 2 2 2 2
    ./a.out R 2 2 2 2 2
    ./a.out R 2 4 8 16
    ./a.out R 0 0 0 2
    ./a.out R 0 0 2 2
    ./a.out R 2 0 2 2
    ./a.out R 2 0 2 4 
    ./a.out R 0 2 2 4
    ./a.out R 0 2 0 4

    echo "LEFT"
    ./a.out L 2 2 2 2 2
    ./a.out L 2 2 0 0
    ./a.out L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
    ./a.out L 2 2 2 2
    ./a.out L 2 2 2 2 2
    ./a.out L 2 4 8 16
    ./a.out L 0 0 0 2
    ./a.out L 0 0 2 2
    ./a.out L 2 0 2 2
    ./a.out L 2 0 2 4 
    ./a.out L 0 2 2 4
    ./a.out L 0 2 0 4


    # ./a.out R 2 2 2 2
    # ./a.out R 2 2 2 2 2
    # ./a.out R 2 4 8 16
    # ./a.out R 4 4 8 16 
} &>> tests/0-log

#diff -d tests/0-log tests/0-output
cat tests/0-log
