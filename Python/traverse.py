#!/usr/bin/python

#a = [1,2,3,4,5]

def traverse1(a):
	print "traverse 1\n"
	for i in range(len(a)):
		print str(i) + "\t" + str(a[i]) + "\n"


def traverse2(a):
	print "traverse 2\n"
	for index,item in enumerate(a):
		print str(index) + "\t" + str(item) + "\n"
	return

#traverse1(a)
#traverse2(a)
