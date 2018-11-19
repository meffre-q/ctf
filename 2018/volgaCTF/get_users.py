#!/usr/bin/env python

with open("capture.txt") as f:
    for line in f:
        # print line[0:-1]
        if line[0:-1] is "users":
            print line
