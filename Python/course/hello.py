#!/usr/bin/env python   
# -*- coding : utf-8 -*-

#both ok
__doc__ = 'my first python'
'my first python '

__anthor__ = "QingXU"


import sys

try:
    import cStringIO as StringIO
except ImportError:   #catch a ImportError exception
    import StringIO


#private function
def __my_name():
    return "Qing"

def test():
    args = sys.argv
    print "parameter : ", args
    if len(args) == 1:
        print "Hello,my first python file..."
    elif len(args) == 2:
        print "Hello, %s & %s !" %( args[1], __my_name())
    else:
        print "Illegal parameter!!!"

if __name__ == '__main__':
    print "main in hello module"
    test()

_a = 100
__a = 1000
a = 10

