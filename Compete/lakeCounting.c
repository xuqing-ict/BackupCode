//数一个区域的八联通的区域的个数 #include <iostream> #include <vector>

#include <stdlib.h>
#include <stdio.h>

void dfs(char **field, const int row, const int column,const int m ,const int n)
{
  field[row][column] = '.';

  for(int i = -1 ; i <= 1; ++i)
  {
    for(int j = -1 ; j <= 1; ++j)
    {
      int dx = row+i, dy = column+j;
      if(dx >= 0 && dx < m && dy >= 0 && dy < n && field[dx][dy] == 'W')
      {
        //field[dx][dy] = '.';
        dfs(field,dx,dy);
      }
    }
    
  }
}


int Count(char ** field,const int m, const int n)
{
	int ret = 0;
	if (m == 0) return 0;

	for(int i = 0 ; i < m ; ++i)
		for(int j = 0 ; j < n ; ++j)
			if (field[i][j] == 'W')
			{
				dfs(field,i,j);
				ret++;
			}
	return ret;
}





int main()
{

    int m,n;
    int **A;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        A = new char* [m];
        for(int i=0;i<m;++i)
            A[i]=new char[n+1];
        for(int i=0;i<m;++i)
        {
            scanf("%s",&(A[i]));
        }

        for(int i=0;i<m;++i)
            printf("%s\n",A[i]);
        printf("%d\n",Count(A,m,n));
    }
    for(int i=0;i<m;++i)
        delete [] (A[i]);
    return 0;
}
