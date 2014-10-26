#include <bits/stdc++.h>
using namespace std;

/*
 * eg. N = 3
 * 1 2 6
 * 3 5 7
 * 4 8 9
 * */
void print(const int n)
{
    if(n < 0) return;
    vector<vector<int> > A(n,vector<int>(n,0));
    int num=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            if(i&1)
                A[i-j][j-1] = num++;
            else
                A[j-1][i-j] = num++;
        }
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=n-i;++j)
        {
            if((n+i) &1)
                A[n-j][i+j-1] = num++;
            else
                A[i+j-1][n-j] = num++;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            cout << A[i][j] << "\t";
        cout <<endl;
    }
}

/*
 * N = 3
 * 1 2 3
 * 8 9 4
 * 7 6 5
 * */
void print2(const int n)
{
    int num=1; //从1开始
    int left=0,right=n-1,up=0,down=n-1;//分别标志4个角
    vector<vector<int> > A(n,vector<int>(n,0));
    while(left<=right)
    {
	//先打印4个角
        A[up][left]=num;
        A[up][right] = A[up][left] + (right-left);
        A[down][right] = A[up][right] + (right-left);
        A[down][left] = A[down][right] + (right-left);
	//再打印行即可
        for(int i=left+1;i<right;++i)
            A[up][i] = A[up][i-1]+1;
        for(int i=up+1;i<down;++i)
            A[i][right] = A[i-1][right]+1;
        for(int i=right-1;i>left;--i)
            A[down][i] = A[down][i+1]+1;
        for(int i=down-1;i>up;--i)
            A[i][left]= A[i+1][left]+1;
        ++left;--right;++up;--down;
        num = A[left][up-1]+1; //更新下一个循环的起始点
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            cout << A[i][j] << "\t";
        cout << endl;
    }

}
/*
 * n=5:
 * 1 2 9 10 25
 * 4 3 8 11 24
 * 5 6 7 12 23
 * 16 15 14 13 22
 * 17 18 19 20 21
 * */
void print3(const int n)
{
    if(n < 0) return;
    vector<vector<int> > A(n,vector<int>(n,0));
    int num=1;
    for(int i=0;i<n;++i)
    {
        //从两边往（i,i）位置处打印即可
        if(i & 1)
        {
            for(int k=0;k<=i;++k)A[k][i] = num++;
            for(int k=i-1;k>=0;--k)A[i][k] = num++;
        }
        else
        {
            //这里充分体现了，只要交换x与y的位置，就可以逆向的打印了！！！
            for(int k=0;k<=i;++k)A[i][k] = num++;
            for(int k=i-1;k>=0;--k)A[k][i] = num++;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            cout << A[i][j] << "\t";
        cout << endl;
    }
}
int main(void)
{
    int n;
    while(1)
    {
        cin >> n;
        //print(n);
        //print2(n);
        print3(n);
    }
    return 0;
}
