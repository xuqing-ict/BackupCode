#!/usr/bin/env python

import functools
def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print "%s %s()" %(text, func.__name__)
            return func(*args, **kw)
        return wrapper
    return decorator

def log2(func):
    def decorator(*args, **kw):
        return func(*args, **kw)
    return decorator

@log("decorator need parameter version1") 
@log("decorator need parameter version2") 
def date2(x,y):
    print "2014-11-5"
    print "x, y ", x, y
    return x


date2 = log('execute1')(date2)
date2 = log('execute2')(date2)
date2 = log('execute3')(date2)
date2(2, 3)
