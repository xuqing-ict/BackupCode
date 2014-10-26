// Last Update:2014-07-28 11:30:33
/**
 * @file UnionFind.h
 * @brief union find
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-28
 */

#ifndef _UNION_FIND_H
#define _UNION_FIND_H

#include <bits/stdc++.h>
using namespace std;

typedef int DisjSet[numSets+1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void setUnion(DisjSet S, SetType Root1, SetType root2);
SetType Find(ElementType X, DisjSet S);

#endif  /*_UNION_FIND_H*/
