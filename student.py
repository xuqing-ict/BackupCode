class Student(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def print_name(self):
        print 'Name: %s' % self.name
    def print_age(self):
        print 'Age: %s' % self.age

std = Student('ljshou', 25)
std.print_name()
std.print_age()
