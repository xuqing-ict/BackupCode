#!/usr/bin/python
import traverse

strs = "12 34 56"
print strs.split()[-1]
print strs.split()[-2]
print strs.split()[-3]

segs = strs.split()

traverse.traverse2(segs)
