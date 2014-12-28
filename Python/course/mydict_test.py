import unittest
from myDict import Dict

class TestDir(inittest,TestCase):
    def test_init(self):
        d = Dict(a=1,b='test')
        self.assertEquals(d.a,1)
        self.assertEquals(d.b,'test')
        self.assertTrue(isinstance(d,dict))

    def test_key(self):
        d = Dict()
        d['key'] = 'value'
        self.assertEquals(id,key,'value')

    def test_attr(self):
        d = Dict()
        d.key = 'value'
        self.assertTrue('key' in d)
        self.assertEquals(d['key'],'value')
