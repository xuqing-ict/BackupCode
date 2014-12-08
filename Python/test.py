#!/usr/bin/env python

import sys

def addend(L=[]):
    L.append('END')
    return L

a = [1,2,3,4]
addend(a)
print a #[1,2,3,'END']
print addend() # ['END']
print addend() # ['END','END']
print addend() # ['END','END','END']


def addend2(L = None):
    if L is None:
        L = []
    L.append('END')
    return L

print addend2() # ['END']
print addend2() # ['END']
print addend2() # ['END']

#function with uncertain parameters
def calc(*numbers):
    print "num: " , numbers
    print isinstance(numbers,tuple)
    sm = 0
    for n in numbers:
        sm += n;
    return sm
print calc(1,2)
print calc()
print calc(1,2,3,4,5,6)
print calc(*[1,2,3,4])

def person(name,age,**kw):
    print "name : ", name , "age: " ,age, "other : " , kw
    print isinstance(kw,dict)
person("Tom",15)
person("Jack",24, city="Beijing", job="software engineer")
kw = {'city': "Beijing", "job": "software engineer"}
person('Jack',24,city=kw["city"],job=kw["job"])
person("Jack",24,**kw)



def func(a,b,c=0,*args,**kw):
    print a,b,c,args,kw
    assert isinstance(args, tuple) == True
    assert isinstance(kw, dict) == True
print "func(1,2)"
func(1,2)
print "func(1,2,c=3)"
func(1,2,c=3)
print "func(1,2,3)"
func(1,2,3)
print "func(1,2,3,'a','b')"
func(1,2,3,'a','b')
print "func(1,2,3,'a','b',x=99)"
func(1,2,3,'a','b',x=99)

#invoke the function only with a tuple and a dict 
a = (1,2,3,'a')
kw = {"x":99}
func(*a,**kw)

#splice
L = range(10)
print L[1:] #[2,3,4,5,6,7,8,9]
print L[1:5] # [1,2,3,4]
print L[::2] #[0,2,4,6,8]
print L[1::2] #[1,3,5,7,9]

#traverse a dict
d = {'a': 1, 'b': 2, 'c': 3}
#traverse key
print "key : ",
for key in d:
    print key,
#traverse value
print "value : ",
for value in d.itervalues():
    print value,

print "pairs : ",
#traverse (key,value) pair
for key,value in d.iteritems():
    print key,value

# verify one object is iterable or not
from collections import Iterable
print "\"abc\" is iterable : "  , isinstance("abc",Iterable) #True
print "[1,2,3] is iterable : "  , isinstance([1,2,3],Iterable) #True
print "list is iterable : "  , isinstance(list,Iterable)
print "dict is iterable : "  , isinstance(dict,Iterable)

#iterative 
#traverse a list using index
L = [1,2,3,4]
for i,value in enumerate(L):
    print i, value

#traverse using two parameters
for i,j in [(1,2),(3,4),(5,6)]:
        print i,j

#list 
L = range(3,5)
print "L : " , L
L = [x*x for x in range(10)]
print "L : " , L
L = [x*x for x in range(10) if x&1 == 0]
print "L : " , L
#all permutation
L = [m+n for m in "ABC" for n in "123"]
print "L : " , L

L = [m+n+x for m in "abc" for n in "123" for x in "ABC"]
print "L : ", L, len(L)

#list all files and directory 
import os
L = [d for d in os.listdir("./test")]
for idx,value in enumerate(L):
    print idx, value
d = {'x': 'A', 'y':'B','z':'C'}
L = [k + "=" + v for k,v in d.iteritems()]
print "L : ", L
L = ["Good", "Morning","Dear","Mummy"]
L = [s.lower() for s in L]
print "L : ", L
#list contain non-string element
L = ["Good", "Morning",18,"Dear","Mummy"]
L= [s.lower() for s in L if isinstance(s,str)]
print "L : ", L

#generator
L = [x*x for x in range(10)]
print "L : ", L
# define a generator , version 1
g = (x*x for x in range(10))
print "g : ", g

#print elements in generator
##exit when throw an exception , so we need a try catch block
print "g: ",
try:
    while 1: 
        print g.next()
except:
    print "Get an exception"

g = (x*x for x in range(10))
#Since the generator is a iterable object
print "generator is iterable ? ", isinstance(g,Iterable)
print "g : ",
for n in g:
    print n,


#print Fibnacci number list
def fib(cnt):
    n,a,b = 0,0,1
    while n < cnt:
        print b
        a,b = b,a+b
        n += 1
fib(6)
#define a generator, version 2
#convert the def function to a generator function
def fib(cnt):
    n,a,b = 0, 0 , 1
    while n < cnt:
        yield b
        a,b = b,a+b
        n += 1
print fib(6)
        
# the procedure of generator and function are different

def odd():
    print "step 1"
    yield 1
    print "step 2"
    yield 2
    print "step 3"
    yield 3

o = odd()
try:
    while 1:
        o.next()
except:
    print "end"

for n in odd():
    print n



#map  reduce built-in functions
L = [x for x in range(10)]
def f(x): return x*x
print "res : ", map(f,L)
def add(x,y): return x+y
print reduce(add,L)
def fn(x,y): return x*10+y
print reduce(fn,L)
#convert str to int
def char2num(s):
    return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s] 
print reduce(fn,map(char2num,"13579"))

#converge them into one str2int function , version 1
def str2int(s):
    def fn(x,y):
        return x*10+y
    def char2num(s):
        return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s]
    return reduce(fn,map(char2num,s))
print isinstance(str2int("45678"), int)


#converge them using lambda function, version 2
def str2int(s):
    return reduce(lambda x,y: x*10+y,map(char2num,s))
print str2int("1908")

#sort
#sorted is a high order function
L = [21,9,12,435,3,63]
print sorted(L)
def cmp_func(x,y):
    if x > y: return 1
    elif x < y : return -1
    else: return 0
print sorted(L,cmp_func)
#sort string list by a ignoring case
def cmp_ignore(x,y):
    s1 = x.lower()
    s2 = y.lower()
    if s1 < s2: return -1
    elif s1 > s2: return 1
    else: return 0
L = ["abd","fag","ABGD","afD"]
print sorted(L,cmp_ignore)
#return functions
def lazy_sum(*args):
    def Sum():
        ax = 0
        for n in  args:
            ax += n
        return ax
    return Sum
f = lazy_sum(1,2,3,4)
f1 = lazy_sum(1,2,3,4)
print f
print f()
print f == f1

#anonymous function
L = [i for i in range(10)]
print map(lambda x : x *x , L)
f = lambda x : x *x
print map(f,L)
print f
print f(3)

def distance(x,y):
    return lambda : x*x + y*y


#decorator
print "decorator part..."
#add log info but do not modify the date function
def log(func):
    def wrapper(*args, **kw):
        print "call %s(): " %func.__name__
        return func(*args, **kw)
    return wrapper

#if the decorator needs parameters, we need define a more hihher order function.
def log(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print "%s %s()" %(text, func.__name__)
            return func(*args, **kw)
        return wrapper
    return decorator

#it means we called log(date) instead of calling date() when we call date() only.
@log("print today...") 
def date():
    print "2014-11-5"
f = date
date()
f()


@log("decorator need parameter version") #it means we called log(date) instead of calling date() when we call date() only.
def date2():
    print "2014-11-5"

#f = date2 # f id a function object
#f()
print date2.__name__ # wrapper
date2()
date2 = log("recursice call")(date2)
print date2

# a complete decorator version 1: log has no parameter
import functools
def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print "call %s : " %func.__name__
        return func(*args, **kw)
    return wrapper
@log
def func():
    print "full implementation..."
func()



# a complete decorator version 1: log has no parameter
import functools
def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print "%s %s" %(text,func.__name__)
            return func(*args, **kw)
        return wrapper
    return decorator

print "Test full implementation of decorator"
@log("paramete of log")
def func():
    print "full implementation..."
func()

#The decorator design pattern in Python can be implemented by function or class

#define a log supporting the parameter is void or non-void
import functools
def log(*args):
    def decorator(func):
        @functiontools.wraps(func)
        def wrapper(*args, **kw):
            print "%s %s : " %(args,func)
            return func(*args, **kw)
        return wrapper
    return decorator



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



#partial
print int("12345")
#define a partial function by decide some parameters from right to left
import functools
int2 = functools.partial(int,base=2)
print int2("100",base=10)
print int2("100")

def f(a1=1,a2=2,a3=3):
    print 'In f : ' , a1, a2, a3

def g(a1,a2,a3):
    print "In g : ", a1, a2, a3
f(2,3,4) # 2 3 4
f2 = functools.partial(f,a1=22,a3=33)
f2()

g(11,22,33)
g2 = functools.partial(g,a2=111, a3=333)
g2(111)
