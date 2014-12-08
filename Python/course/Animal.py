#!/usr/bin/env python
#*-* coding : utf-8 *-*

'inheritence and polymorphism'

import sys

class Animal(object):
    def run(self):
        print "Animal is running..."

class Dog(Animal):
    def run(self):
        print "Dog is running..."
    def eat(self):
        print "Dog eat bones..."

class Cat(Animal):
    def run(self):
        print "Cat is running..."
    def sleep(self):
        print "Cat is sleeping..."

def run_2(animal):
    animal.run()
    animal.run()

run_2(Animal())



#type info
import types
print type(123)
print type('abc')
print type('abc') == types.StringType
print type([]) == types.ListType
print type(str) == types.TypeType

#here, isinstance equals to type
print isinstance(123,(str,Dog,Animal))

#print all attributes of object
print dir("abc")

