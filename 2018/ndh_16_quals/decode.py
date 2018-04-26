#!/usr/bin/env python

crypt=[
    21,
    91,
    20,
    0,
    126,
    0,
    61,
    24,
    2,
    82,
    7,
    17,
    88,
    22,
    18,
    21,
    114,
    117,
    15,
    80,
    59,
    24
]
key="MagicMagicMagicMagicMagic"
decrypt=""
i=0

while i < len(crypt):
    decrypt+=chr(crypt[i]^ord(key[i]))
    i+=1
print decrypt
