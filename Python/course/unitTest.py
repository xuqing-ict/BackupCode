#!/usr/bin/env python
#-*- coding : utf-8 -*-

__author__ = "QingXu"

import sys
import doctest

class MyDict(dict):
    """
    >>> d1 = MyDict()
    >>> d1['x'] = 100
    >>> d1['x']
    100
    >>> d1.x
    100
    >>> d1.y = 200
    >>> d1['y']
    200
    >>> d2 = MyDict(a=1,b=2,c='3')
    >>> d2.c
    '3'
    >>> d2['empty']
    Traceback (most recent call last):
    ... 
    keyError: 'empty'
    >>> d2.empty
    Traceback (most recent call last):
    ...
    AttributeError: 'MyDict' object has no attributes 'empty'
    """

    def __init__(self, **kw):
        super(MyDict, self).__init__(**kw)
    def __getattr__(self, key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'dict' object has no attributes '%s'" %key)

    def __setattr__(self,key,value):
        self[key] = value

'''
import unittest

class TestMyDict(unittest.TestCase):
    #Only the functions with prefix "test" would be called.
    def setUp(self): print "In..."
    def tearDown(self): print "Out..."
    def test_init(self):
        d = MyDict(a=1,b='Test')
        self.assertEquals(d.a,1)
        self.assertEquals(d.b,'Test')
        self.assertTrue(isinstance(d,dict))
    def test_key(self):
        d = MyDict()
        d['key'] = 'value'
        self.assertEquals(d['key'],'value')
    def test_attr(self):
        d = MyDict()
        d.key = 'value'
        self.assertTrue('key' in d)
        self.assertEquals(d['key'],'value')
    def test_keyerror(self):
        d = MyDict()
        with self.assertRaises(KeyError):
            value = d['empty']
    def test_attrerror(self):
        d = MyDict()
        with self.assertRaises(AttributeError):
            value = d.empty
'''
if __name__ == "__main__":
    doctest.testmod()
