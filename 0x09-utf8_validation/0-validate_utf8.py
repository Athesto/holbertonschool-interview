#!/usr/bin/python3j
''' 0x09. UTF-8 Validation '''


def validUTF8(data):
    '''
    validUTF8 - determines if input is a valid UTF-8 encoding.
    @data: list of integers
    Return: True if is a valid UTF-8, False otherwise
    '''
    print(data)
    for i in range(len(data)):
        num = data[i] & 0xFF
        print(num, end=",")
        if num >> 7 == 0:
            continue
        if num >> 5 == 0b110 and i < len(data) - 1:
            if data[i + 1] >> 6 == 2:
                i += 1
                continue
        if num >> 4 == 0b1110 and i < len(data) - 2:
            if data[i + 1] >> 6 == data[i + 2] >> 6 == 2:
                i += 2
                continue
        if num >> 3 == 0b11110 and i < len(data) - 3:
            if data[i + 1] >> 6 == data[i + 2] >> 6 == data[i + 3] >> 6 == 2:
                i += 3
                continue
        return False
    return True
