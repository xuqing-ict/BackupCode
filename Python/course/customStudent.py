#!/usr/bin/env python
__author__ = "QingXu"
'customized class'

import sys

class Student(object):
    def __init__(self,name):
        self.name = name
    def __str__(self):
        return "Student object (name : %s)" %(self.name)
    __repr__ = __str__
    def __getattr__(self,attr):
        if attr == "age": return -1
        raise AttributeError("\"Student\" object has not attribute \'%s\'" %attr)
    def __call__(self):
        print "My name is : %s" %self.name

s1 = Student("Micheal")
print "name : " , s1.name
print "age : ", s1.age
#print "score : ", s1.score
s1()
print callable(s1)

class Fib(object):
    def __init__(self):
        self.a , self.b = 0,1 
    def __iter__(self): return self
    def __str__(self):
        a,b = 1,1
        s = ''
        while b < 100000:
            s += str(a) 
            s += ','
            a,b = b,a+b
        return s
    def next(self):
        self.a,self.b = self.b, self.a+self.b
        if self.a > 100000:
            raise StopIteration()
        return self.a
    def __getitem__(self,n):
        if isinstance(n,int):
            a,b = 1,1
            for x in range(n):
                a,b = b,a+b
            return a
        if isinstance(n,slice):
            if n.start == None: start = 0
            else: start = n.start
            if n.step == None: step = 1
            else: step = n.step 
            if n.stop == None: stop = -1 #illegal one
            else: stop = n.stop
            print "slice : ", start,step,stop
            a,b = 1,1
            L = []
            for x in range(stop):
                if x >= start and (x-start)%step == 0:
                    L.append(a)
                a,b = b,a+b
                if a > 100000: break #for the unknown stop
            return L

class Fib2(object):
    def __init__(self):
        self.a , self.b = 0,1 
        self.number = [0, 1]

    def __iter__(self): return self

    def __str__(self):
        a,b = 0,1
        s = ''
        while b < 100000:
            s += str(a) 
            s += ','
            a,b = b,a+b
        return s

    def next(self):
        self.a, self.b = self.b, self.a+self.b
        if self.b > 100000:
            raise StopIteration()
        self.number.append(self.b)
        return self.b

    def __getitem__(self, n):
        if isinstance(n,int):
            print "n is int"
            if len(self.number) >= n+1:
                return self.number[n]
            for x in range(n+1 - len(self.number)):
                self.a, self.b = self.b, self.a + self.b
                self.number.append(self.b)
            return self.b
        if isinstance(n,slice):
            print "n is slice"
            if n.start == None: start = 0
            else : start = n.start
            if n.stop == None : stop = -1
            else :  stop = n.stop
            if n.step == None: step = 1
            else: step = n.step
            print "slice : ", start,step,stop,stop
            a,b = 1,1
            L = []
            for x in range(stop):
                if x >= start and (x-start)%step == 0:
                    L.append(a)
                a,b = b,a+b
            return L
'''

f = Fib()
print f
print 0, f[0]
print 1, f[1]
print 10, f[10]
print 100, f[100]
print f
print f[:10:2]
'''
class Chain(object):
    def __init__(self, path = ''):
        self._path = path
    def __getattr__(self,path):
        return Chain('%s/%s' %(self._path,path))
    def __str__(self):
        return self._path
print Chain().xuqing.com
