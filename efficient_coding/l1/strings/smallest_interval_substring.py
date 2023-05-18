#!/usr/bin/env python3

# easy solution

# there is one hidden test case which this solution is passing but C++ solution
# is not, wonder what that is

str = input()
slen = len(str)

for i in range(slen):
    fidx = str.find(str[:i + 1], i + 1)
    if slen % (i + 1) == 0 and fidx == i + 1:
        repeats = slen // (i + 1)
        new_str = str[:i + 1] * repeats
        if new_str == str:
            print(str[:i + 1])
            exit()

print(str)
