#!/usr/bin/env python
#-*- coding : utf-8 *-*

__author__ = "QingXu"

#bad example
def foo():
    r = some_function()
    if r == -1: return -1
    return r

def bar():
    r = foo()
    if r == -1 :  print "ERROR"
    else: pass

# try ,except, finally
try:
    print "try...."
    r = 10/0
    print "result : ", r
except ZeroDivisionError, e:
    print "Exception : ", e
finally:
    print "finally"
print "END"

# try ,except, finally for varied error
try:
    print "try...."
    r = 10/int('a')
    print "result : ", r
except ValueError , e:
    print "ValueError : ", e
except ZeroDivisionError, e:
    print "ZeroDivisionError : ", e
else:
    print "no error in else"
finally:
    print "finally"
print "END"



try:
    print "try...."
    r = 10/int('a')
    print "result : ", r
except BaseException, e:
    print "BaseException: ", e
else:
    print "no error in else"
finally:
    print "finally"
print "END"

#log the error
import logging
print "LOG..."
def foo(s): return 10/int(s)
def bar(s): return foo(s)*2
def main():
    try:
        bar('0')
    except StandardError,e:
        logging.exception(e)

main()
print "END"

'''
print "raise current exception"
#user define the exception class
class FooError(StandardError): pass
def foo(s):
    n = int(s)
    if n == 0:
        raise FooError('invalid value : %s' %s)
    return 10/n

foo(0)
'''
'''
#using raise to transit current exception
def foo(s):
    n = int(s)
    return 10/n
def bar(s):
    try:
        return foo(s)*2
    except StandardError,e:
        print "StandardError : ", e
        raise
    
def main():
    bar('0')
main()
'''
print ">>> Assertion Test...."

#assert
def foo(s):
    n = int(s)
    assert n != 0 , 'n is zero'
    return 10/n
foo('0')

