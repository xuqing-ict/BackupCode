#!/usr/bin/env python
# -*- coding : utf-8 -*-

__author__ = "QingXU"

import sys

class Student(object): #class Student inherient the object
    def __init__(self, name, score):
        self.__name = name
        self.__score = score
    def display(self):
        print "%s : %s"  %(self.__name, self.__score)
    #get
    def get_score(self): return self.__score
    def get_name(self): return self.__name
    #set
    def set_score(self,score): 
        if not isinstance(score,int): 
            raise ValueError("bad score!!!")
        if 0 <= score <= 100:
            self.__score = score
        else:
            raise ValueError("invalid number!!!")

    def set_name(self,name): 
        if not isinstance(name, str):
            raise ValueError("bad name...")
        self.__name = name

    def level(self,score):
        if 90 <= self.__score <= 100:
            print "A"
        elif self.__score > score:
            print "B"
        else:
            print "C"

sa = Student("sa",100)
sb = Student("sb",90)
sa.display()
sb.display()
