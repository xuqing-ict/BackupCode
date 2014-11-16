#!/usr/bin/python

import sys

sys.stdout.write("[1] read file\n")
for line in open("tmp.txt","r"):
    print line,
sys.stdout.write("[1] read end\n")

print "[2] read and write from std"
sys.stdout.write("enter your name:")
name = sys.stdin.readline()
sys.stdout.write(name)
print "[2] end"

name = raw_input("Enter your name:")
print name


print "[3] string variable"
s1 = "Hello \
        world1"
s2 = 'Hello world2'

s3 = '''
Hello \
world \
3\
'''

s4 = """
Hello \
world \
4
"""
sys.stdout.write(s1 + "\n")
sys.stdout.write(s2)
sys.stdout.write(s3)
sys.stdout.write(s4)
