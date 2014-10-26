from numpy import *
import operator

def createDataSet():
	group = array([[1.0,1.1],[1.0,1.0],[0,0],[0,0.1]]);
	labels = ['A','A','B','B']
	return group, labels

def classify(inX, dataSet, labels, k):
	dataSetSize = dataSet.shape[0]
	diffMat = tile(inX, (dataSetSize, 1)) - dataSet
	sqDiffMat = diffMat**2
	print "sqDiffMat : " , sqDiffMat
#sum each line of the matirx
	sqDiffDis = sqDiffMat.sum(axis=1)
	print "sqDiffDis : " , sqDiffDis
	diff = sqDiffDis**0.5
	print "Diff : " ,diff
	sortedDiff = diff.argsort()
	print "sortedDiff : ", sortedDiff
	classCount = {}
	for i in range(k):
		curLabel = labels[sortedDiff[i]]
		classCount[curLabel] = classCount.get(curLabel,0) + 1
	print classCount
	sortedClassCount = sorted(classCount.iteritems(), key=operator.itemgetter(1),reverse=True)
	return sortedClassCount[0][0]
		
	

