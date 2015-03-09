#!/usr/bin/env python
#-*- coding : utf-8 -*-

__author__ = "QingXU"

import sys
import codecs

def readFile(fileName):
    #v1
    f = open(fileName,"r")
    ret = f.read()
    print ret
    print "len = ", len(ret)
#v2
    try:
        f = open(fileName,"r")
        print f.read()
    finally:
        if f: f.close()
#v3
    with open(fileName, "r") as f:
        #print f.read() #read the all contents
        lines = f.readlines()
        print lines
        print "line number = ", len(lines)
#read configuration
    with open(fileName,"r") as f:
        for line in f.readlines():
            print (line.strip())

'''
# read image or video
    f = open("./test.img","rb")
    print f.read()
'''



# read gbk coding
f = open("./gbk.txt","rb")
u = f.read().decode('gbk')
print u

with codecs.open('./gbk.txt',"r",'gbk') as f:
    print f.read()
readFile("test.txt")
