#!/usr/bin/env python

#__future__
from __future__ import unicode_literals
from __future__ import division

import hello

hello.test()
print hello.a

#do not do this because the _xx , __xxx and __xxx__ are private.
#print hello._a
#print hello.__a
#print "call privat func : " , hello.__my_name()


import Image
im = Image.open("./test.png")
print im.format, im.size, im.mode
im.thumbnail((200,100)) #200*100 
im.save("thumbnail.png",'PNG')


print '\'xxx\' is unicode ? ', isinstance('xxx',unicode)
print 'u\'xxx\' is unicode ? ', isinstance(u'xxx',unicode)
print '\'xxx\' is str ? ', isinstance('xxx',str)
print 'b\'xxx\' is str? ', isinstance(b'xxx',str)

print "10/3 = ", 10/3
print "10.0/3 = ", 10.0/3
print "10//3 = ", 10//3
