#!/usr/bin/env python
#-*- coding:utf-8 *-*

__author__ = "QingXu"

class Dict(dict):
    def __init__(self,**kw):
        super(Dict,self).__init__(**kw)

    def __getattr(self,key):
        try:
            return self[key]
        except:
            raise AttributeError(r"'Dict' object has no attribute '%s'" %key)
    def __setattr__(self,key,value):
        self[key] = value



