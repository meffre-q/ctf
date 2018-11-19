#!/usr/bin/env python

goal="flag{an0"
crypt="\x1f\x0d\x05\x08\x0f\x3e\x1d\x5d\x1b\x07\x07\x2d\x30\x0c\x48\x0f\x3b\x0d\x44\x32\x11\x32\x08\x5f\x0c\x3a\x12\x00"
key=""
i=0
j=0x0

while i<len(goal):
    while j<255:
        if chr(ord(crypt[i])^j)==goal[i]:
            key+=chr(j)
        j+=1
    i+=1
    j=0
print key
i=0
decrypt=""
while i<len(crypt):
    decrypt+=chr(ord(key[i]) ^ord(crypt[i]))
    i+=1
print decrypt
