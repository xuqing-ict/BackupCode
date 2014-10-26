#!/usr/bin/python
import sys
import operator
import commands

import traverse

bob = ['Bob Smith', 42, 30000, 'software']
sue = ['Sue Jones', 45, 40000, 'hardware']

people = [bob, sue]

#some simple test
print bob[0], sue[2]
print bob[0].split()[-1]

for person in people:
	print person[0].split()[-1]
pays = [person[2] for person in people]
traverse.traverse1(pays)
print sum(person[2] for person in people)
people.append(['Tom', 50, 0, None])
print len(people)

print people[-1][0]

NAME,AGE,PAY = range(3)
print bob[NAME]
print bob[AGE]
print bob[PAY]
print bob.index(42)

bob2 = [['name','Bob Smith'],['age',42],['pay',30000]]
sue2 = [['name','Sue Jones'],['age',45],['pay',40000]]

people2 = [bob2, sue2]
for person in people2:
	for (name, value) in person:
		if name == 'name':
			print value

def field(record, label):
	for (fname,fvalue) in record:
		if fname == label:
			return fvalue
print field(bob2,'name')
print field(sue2, 'pay')

for person in people2:
	print field(person, 'age')

bob3 = {'name':'Bob Smith', 'age':42,'pay':30000, 'job':'dev'}
sue3 = {'name':'Sue Jones', 'age':45,'pay':40000, 'job':'hdw'}
print bob3['name']
print sue3['pay']
bob3['pay'] *= 2;
print bob3['pay']



bob4 = dict(name = 'Bob Smith',age = 42, pay = 30000, job = 'dev')
sue4 = dict(name = 'Sue Jones',age = 35, pay = 40000, job = 'hdw')
print bob4
print sue4

sue5 = {}
sue5['name'] = 'Sue Jones'
sue5['age'] = 45
print sue5

names = ['name','age','pay','job']
labels = ['Sue Jones',45, 40000, 'dev']

#zip 就是将names与labels中的元素一一对应，形成一个turple
print list(zip(names,labels))

sue = dict(zip(names,labels))
print sue

fields = ['name','age','job','pay']
record = dict.fromkeys(fields,'?')
print record
print sue3
print bob3

people3 = [bob3,sue3]
for person in people3:
	#print(person['name'],person['pay'], sep=' ') //python 3
	print person['name'], ; sys.stdout.softspace=True;print person['pay']
	#print person['name'], ',', person['pay']
	print "%s %s" %(person['name'], person['pay'])

names = [person['name'] for person in people3]
print names
print list(map((lambda x:x['name']),people3))
print sum(person['pay'] for person in people3)

#lambda
def f(x): return x**2
print f(5)

g = lambda x: x**2
print g(5)

#lambda define s nomymous function
def make_increment(n): return lambda x: x+n
f1 = make_increment(22)
g1 = make_increment(44)

print f1(2), g1(2)

print make_increment(22)(33)

elems = [1,2,3,4]
print list(map(f,elems))
print list(map(lambda x: x**2, elems))
print list(map(lambda x: x**2 , [1,2,3,4]))
print list(map(pow, [1,2,3],[3,4,5]))
print list(map(lambda x, y: x+y, [1,2,3],[1,2,3]))
print map(None,[1,2,3],[1,2,3])

#filter(aFunc, aSequence)
print filter(lambda x: x%2 == 0, [1,2,3,4,5,6])

print reduce(lambda x, y: x+y, [1,2,3,4])

def myReduce(func, seq):
	ret = seq[0]
	for elem in seq[1:]:
		ret = func(ret, elem)
	return ret
print myReduce(lambda x,y: x+y, [1,3,5,7])
print myReduce(lambda x, y: x+y, ['Hold ', 'on!'])
seqs = ['Hold ','on!']
print ''.join(seqs)
print reduce(operator.add, seqs)
print reduce(operator.add,[],-1)

sentence = 'It is a big surprise'
words = sentence.split()
print words
lengths = map(lambda x: len(x), words)
print lengths
print map(lambda x: len(x), 'I am a student'.split())



#commands bag
mount=commands.getoutput('mount -v')
print 'DEBUG'
print mount
lines = mount.splitlines()
print 'DEBUG'
print lines[0]
print lines[0].split()
points = map(lambda line:line.split()[2],lines)


print 'DEBUG'
print points


lines =  commands.getoutput('ls')
print lines

print [rec['name'] for rec in people3 if rec['age'] >= 45]
g =  ((rec['name'] if rec['age'] >= 45 else rec['age']) for rec in people3)
#g = ((rec['age'] ** 2 if rec['age'] >= 45 else rec['age']) for rec in people3)
print g.next()
print next(g)
