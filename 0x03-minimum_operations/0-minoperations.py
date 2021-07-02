#!/usr/bin/python3
'''
0x03. Minimum Operations
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste.
Given a number n, write a method that calculates the fewest number
of operations needed to result in exactly n H characters in the file.

'''


def minOperations(n):
    '''
    @n: Expected input
    Return: integer
    '''
    out = 0
    i = 2
    while (i <= n):
        while (n % i == 0):
            out += i
            n /= i
        i += 1
    return (out)
