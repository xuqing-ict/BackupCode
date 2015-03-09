#!/usr/bin/env python
#-*- coding : utf-8 -*-

__author__ = "QingXu"

import os

print "Process (%s) start ... " %os.getpid()
pid = os.fork()
if pid == 0:
    print "Child Process %s , my parent is %s..." %(os.getpid(),os.getppid())
else:
    print "%s Create a child process %s ..." %(os.getpid(),pid)

from multiprocessing import Process

def run_proc(name):
    print "Run child process %s (%s)... " %(name, os.getpid())


if __name__ == "__main__":
    print "Parent process %s ..." %os.getpid()
    p = Process(target=run_proc,args=('test',))
    print "Process will start."
    p.start()
    p.join()
    print "Process end..."

