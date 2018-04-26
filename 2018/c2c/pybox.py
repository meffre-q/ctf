#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import traceback

print("[SECURE PYTHON v0.0.1]")

targets = __builtins__.__dict__.keys()
for x in targets:
    del __builtins__.__dict__[x]

def raw_input():
    data = ''
    while 1:
        i = sys.stdin.read(1)
        if i == '\n':
            return data
        else:
            data += i

while 1:
    try:
        sys.stdout.write(">>> ")
        data = raw_input()
        exec data
    except:
        sys.stdout.write("¯\_(ツ)_/¯ Whoops ¯\_(ツ)_/¯\n")