#!/usr/bin/python

class people:
    __name = "jack"
    __age = 12
    #ctor
    def __init__(self, _name = "", _age=0):
        print "ctor..."
        self.__name = _name
        self.__age = _age
    def __del__(self):
        print "dtor..."

    def printName(self):
        print self.__name
    def printAge(self):
        print self.__age
    @classmethod
    def setAge(self, x):
        self.__age = x

print "name : ",
people().printName()
p1 = people()
print "p1.name : " ,
p1.printName()
p2 = people()
p2.setAge(100)
print "after change: p1 age : " 
p1.printAge()
print 'p2 age : ' 
p2.printAge()
