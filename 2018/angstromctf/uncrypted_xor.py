#!/usr/bin/env python

#hash="\xfb\xf9\xee\xfc\xe1\xf2\xf5\xea\xff\xc5\xe3\xf5\xef\xc5\xef\xe9\xff\xfe\xc5\xfb\xc5\xe9\xf9\xe8\xf3\xea\xee\xe7"
hash="fbf9eefce1f2f5eaffc5e3f5efc5efe9fffec5fbc5e9f9e8f3eaeee7"
decrypt=""

for i in xrange(0, 255):
    if chr(ord(hash[0])^i) == "a":
	decrypt += "a"
	for j in xrange(0, len(hash)):
	    decrypt += chr(ord(hash[j])^j)
            print decrypt
print "Key ="+str(i)
print decrypt
