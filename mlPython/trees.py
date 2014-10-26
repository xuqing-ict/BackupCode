#!/usr/bin/python

from math import log

def createDataSet():
  dataSet = [[1,1,'yes'],
      [1,1,'yes'],
      [1,0,'no'],
      [0,1,'no']
      [0,1,'no']]

#calculate shannon entropy
def calcChannonEnt(dataSet):
  numEntries = len(dataSet)
  labelCounts = {}
  for elem in dataSet:
    label = elem[-1]
    if label not in labelCounts:
      labelCounts[label] = 0
    labelCounts[label] += 1
  shannonEnt = 0.0
  for key in labelCounts:
    prob = labelCounts[key]/numEntries
    shannonEnt -= (prob)*log(prob,2)
  return shannonEnt
