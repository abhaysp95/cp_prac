#!/usr/bin/python3

try:
    while True:
        str = input()
        words = str.split('.')
        words.reverse()
        print(".".join(words))
except EOFError:
    pass
