//数一个区域的八联通的区域的个数 #include <iostream> #include <vector>

#include <stdlib.h>
#include <stdio.h>

const int MAX_M = 101;
const int MAX_N = 101;
char field[MAX_M][MAX_N];

int M,N;

void dfs(int row, int column)
{
    field[row][column] = '.';

    for(int i = -1 ; i <= 1; ++i)
    {
        for(int j = -1 ; j <= 1; ++j)
        {
            int dx = row+i, dy = column+j;
            if(dx >= 0 && dx < M && dy >= 0 && dy < N && field[dx][dy] == 'W')
                dfs(dx,dy);
        }
    }

}


int Count()
{
    int ret = 0;

    for(int i = 0 ; i < M ; ++i)
        for(int j = 0 ; j < N ; ++j)
            if (field[i][j] == 'W')
            {
                dfs(i,j);
                ret++;
            }
    return ret;
}





int main()
{

    while(scanf("%d%d",&M,&N)!=EOF)
    {
        for(int i=0;i<M;++i)
        {
            scanf("%s",(field[i]));
        }

        printf("%d\n",Count());
    }
    return 0;
}
