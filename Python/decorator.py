#!/usr/bin/env python
import sys

#decorator

import functools
def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print "[log] : call %s(): " %func.__name__
        f = func(*args, **kw)
        return f
    return wrapper

@log
def date():
    print "2014-11-5"

date()
print date.__name__
