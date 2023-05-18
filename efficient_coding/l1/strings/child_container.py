#!/usr/bin/env python3

pstr = input()
cstr = input()

lpstr = len(pstr)
space = [[0 for _ in range(lpstr)] for _ in range(lpstr)]

for i in range(lpstr):
    space[i][i] = 1
    if i + 1 < lpstr:
        if pstr[i] == pstr[i + 1]:
            space[i][i + 1] = 1

for i in range(2, lpstr):
    for j in range(lpstr - i):
        k = i + j
        space[j][k] = 1 if pstr[j] == pstr[k] and space[j + 1][k - 1] == 1 else 0


start, end = 0, 0
for i in range(lpstr):
    for j in range(i, lpstr):
        if space[i][j] == 1:
            if end - start < j - i:
                end = j
                start = i

print(pstr[start:end + 1])
