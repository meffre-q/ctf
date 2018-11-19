#!/usr/bin/env python

with open("./diablo3", "r") as in_file:
    content=in_file.read()

offset=344
key=0xaa
decode_elf=""

for i in xrange(0, len(content)):
    if i in range(offset, 600):
        decode_elf+=chr(ord(content[i])^key)
    else:
        decode_elf+=content[i]

with open("./diablo3.tmp", "w") as out_file:
    out_file.write(decode_elf)
