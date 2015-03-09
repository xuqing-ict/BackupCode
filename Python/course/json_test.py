#!/usr/bin/env python
#-*- coding : utf-8 -*-

import sys
import json

class Student(object):
    def __init__(self,name,age,score):
        self.name = name
        self.age = age
        self.score = score

def student2dict(std):
    return {
            'name': std.name,
            'age' : std.age,
            'score': std.score
        }
def dict2student(d):
    return Student(d['name'], d['age'],d['score'])
         
    
if __name__ == "__main__":
    s = Student("John",25,100)
    print json.dumps(s,default=student2dict)
    print json.dumps(s,default=lambda obj:obj.__dict__)
    json_str = '{"age": 20, "score": 88, "name": "Bob"}'
    s = json.loads(json_str, object_hook=dict2student)
    print s
    #print s['name'],s['age'], s['score']

