/**
 * @file Test.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-10-18
 */

//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <cstdlib>
#include <stdio.h>
#include <set>
#include <map>

using namespace std;

int M[101][101];
int visited[101][101]; //record the visited time of edge
int N;
int P[101]; 
int Parent[101];   //record the parent node 
int USED;

typedef pair<int,int> Pair;

vector<int> getPath(int start, int end)
{
    vector<int> ret;
    queue<int> prev, next;
    prev.push(start);
    //Parent[start] = -1;

    bool V[101];
    fill_n(&V[0],101,false);
    V[start] = true;
    fill_n(&Parent[0],101,0);

    while(!prev.empty())
    {
        int idx = prev.front(); prev.pop();
        if(idx == end) {break;}
        for(int i=1;i<=100;++i)
        {
            if(M[idx][i] && V[i] == false) 
            {
                next.push(i);
                Parent[i] = idx;
                V[i] = true;
            }
        }
        if(prev.empty()) swap(prev,next);
    }

    int t = end;
    while(Parent[end] != 0)
    {
        ret.push_back(end);
        end = Parent[end];
    }
    ret.push_back(start);
    reverse(ret.begin(),ret.end());

    return ret;
}


void legal()
{
    if(USED < 2){ cout << "YES" << endl; return;}

    set<int> exist; //record the node which need to visited
    for(int i = 1; i <= USED;++i) exist.insert(P[i]);


    int start=1;
    if(exist.find(start) != exist.end()) 
    {
        if(((USED > 1) && P[0] == start) || (USED == 1))
            cout << "YES" << endl;
        cout << "NO" << endl;
        return;
    }

    //for each node which need to visit
    for(int i=1;i<=USED;++i)
    {
        // cout << start << " " << P[i] << endl;
        vector<int> path = getPath(start,P[i]);
        for(int l=0;l<path.size();++l)
        {
            //test node legal or not
            int a = path[l];
            for(int j=i+1;j<=USED;++j)
            {
                if(a == P[j])
                { 
                    cout << "NO" << endl;
                    return ;
                }
            }

        }
        //label edge
        for(int m=1;m<path.size();++m)
        {
            visited[path[m-1]][path[m]]++;
            if(visited[path[m-1]][path[m]] > 2)
            {
                cout << "NO" << endl;
                return;
            }
        }
        start = path.back();
    }
    cout << "YES" << endl;
}

int main(void)
{
    int C;
    cin >> C;
    for(int i=0;i<C;++i)
    {
        fill_n(&M[0][0], 101*101, 0);
        fill_n(&visited[0][0], 101*101, 0);
        fill_n(P, 101, 0);
        fill_n(Parent, 101, 0);


        int x,y;
        cin>> N;
        for(int k=1;k<N;++k)
        {
            cin >> x >> y;
            M[x][y] = 1;
            M[y][x] = 1;
        }
        cin >> USED;
        for(int j=1;j<=USED;++j)
            cin >> P[j];
        /*
           cout << "USED:" << USED << endl;
           for(int j=1;j<=USED;++j)
           cout << P[j] ;
           cout << endl;
           */
        legal();
    }
    return 0;
}
