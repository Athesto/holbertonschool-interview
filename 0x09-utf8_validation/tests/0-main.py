#!/usr/bin/python3
"""
Main file for testing
"""
__import__("sys").path.append('.')

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

data = [229, 65, 127, 256]
print(validUTF8(data))


# 2Bytes but array of 1
data = [213]
print(validUTF8(data))

# 2Bytes but 2nd wrong
data = [213, 10]
print(validUTF8(data))
