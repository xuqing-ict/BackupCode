#!/usr/bin/env python
#-*- coding : utf-8 -*-

__author__ = "QingXu"

import os , time, random
from multiprocessing import Pool

def long_time_task(name):
    print "Run task %s (%s)..." %(name, os.getpid())
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print "Task %s run %.2f seconds." %(name, end-start)


if __name__ == "__main__":
    print "Parent process %s." %os.getpid()
    p = Pool()
    for i in range(9): 
        p.apply_async(long_time_task, args = (i,))
    print "Waiting for all subprocess ..."
    p.close()
    p.join()
    print "All subprocess end..."
