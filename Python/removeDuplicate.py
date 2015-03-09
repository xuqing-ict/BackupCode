#!/usr/bin/env python
#-*- coding : utf-8 -*-
import sys

def removeDuplicates(kmer):
    curIndex = 0
    prev = -1
    for i in range(len(kmer)):
        if kmer[i] == prev: continue
        prev = kmer[i]
        kmer[curIndex] = kmer[i]
        curIndex += 1
    if curIndex != len(kmer): 
        del kmer[curIndex:]
    return kmer
        

if __name__ == "__main__":
    kmers = []
    kmer = [1,2,3,3]
    kmer1 = [2,3,4,4,5]
    kmers.append(kmer)
    kmers.append(kmer1)
    for kmer in kmers: print kmer
    for i in range(len(kmers)):
        kmers[i] = removeDuplicates(kmers[i])
    for kmer in kmers: print kmer
