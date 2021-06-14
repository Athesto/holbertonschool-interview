#!/usr/bin/env bash
make

numbers=(
    1
    11
    112
    121
    12345678987654321
    123456789987654321
    1234567898654321
)

answers=(
    '1 is a palindrome.'
    '11 is a palindrome.'
    '112 is not a palindrome.'
    '121 is a palindrome.'
    '12345678987654321 is a palindrome.'
    '123456789987654321 is a palindrome.'
    '1234567898654321 is not a palindrome.'
)


len=${#numbers[@]}
for (( i = 0; i < len; i++ ))  do
    output=$(./a.out "${numbers[$i]}")
    ref="${answers[$i]}"

    if [ "$ref" != "$output" ]; then
        echo -e "\e[31m$output\e[0m"
        echo -e "$ref"
    fi
done
