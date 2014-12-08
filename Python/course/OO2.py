#!/usr/bin/env python
#-*- coding:utf-8 *-*

__author__ = 'QingXU'

'OO for Python'

import sys

'''
class Student(object):
    def __init__(self,name,score):
        self.name = name
        self.score = score
        
class Student(object):
    def __init__(self,name,score):
        self.name = name
        self.score = score
    def get_score(self): return self.score
    def set_score(self,score):
        if not isinstance(score, int):
            raise ValueError("invalid score!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self._score = score

class Student(object):
    def __init__(self,name,score):
        self._name = name
        self._score = score
    @property
    def score(self): return self._score
    @score.setter
    def score(self,score):
        if not isinstance(score,int):
            raise ValueError("invalid score!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self._score = score
    @property
    def name(self): return self._name
s1 = Student("Lily", 90)
s1._name = "Lucy"
#s1.name = "Lily"
s1.score = 100
'''
class Student(object):
    def __init__(self,name,score):
        self.name = name
        self.score = score
    @property
    def score(self): return self.score
    @score.setter
    def score(self,score):
        if not isinstance(score,int):
            raise ValueError("invalid score!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self.score = score
    @property
    def name(self): return self.name
    
    def func(self):
        self.score = score

s1 = Student("Lily", 90)
s1.func()

'''

class Student(object):
    __slots__ = ('name', 'age')

class MiddleStudent(Student):
    __slots = ('score')
    def get_score(self): return self.score
    def set_score(self,score):
        if not isinstance(score, int):
            raise ValueError("invalid score!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self._score = score

s1 = Student()
s1.name = "Micheal"
s1.age = 17
print s1.name, s1.age

m1 = MiddleStudent()
m1.name = "Tracy"
m1.age = 30
m1.score = 100

print m1.name, m1.age, m1.score

#by define set_score member function, we can check the parameter
#but we can using @ decorator to avoid this method.


class MiddleStudent(object):
    #__slots__ = ('_score')
    def __init__(self):
        self._score = 100

    @property
    def score(self): return self._score
    @score.setter
    def score(self,score):
        if not isinstance(score, int):
            raise ValueError("invalid parameter!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self._score = score

m2 = MiddleStudent()
m2.score = 99
print m2.score

#????
print "HERE!!!!"
class Person(object):
    def __init__(self):
        self._birth = 100
    @property
    def birth(self):
        print "score get in Person"
        return self._birth
    @birth.setter
    def birth(self,birth):
        print "_birth set in Person"
        self._birth = birth

    @property
    def age(self):
        return 2014-self._birth

p1 = Person()
p1._birth = 1991
p1.age
print p1._birth, p1.age

print "HERE!!!!"


class Parrot(object):
    def __init__(self):
        self._voltage = 10000
    @property
    def voltage(self):
        return self._voltage
    @voltage.setter
    def voltage(self,voltage):
        self._voltage = voltage

if __name__ == "__main__":
    p = Parrot()
    print p.voltage 
    p.voltage = 9999
    print p.voltage 
'''
