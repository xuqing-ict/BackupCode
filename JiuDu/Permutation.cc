/**
 * @file Permutation.cc
 * @brief permutation
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-31
 */

#include <bits/stdc++.h>
using namespace std;
/*
void permutation(char *s,char *cur)
{
 if(*cur == '\0')
 {
      cout << s << endl;
      return;
 }
  for(char *ch = cur; *ch != '\0' ; ++ch)
  {
    swap(*cur,*ch);
    permutation(s,cur+1);
    tmp=*cur;*cur=*ch;*ch=tmp;
    swap(*cur,*ch);
  }

}
void combination(char *s, char *cur, int len)
{
}
int main()
{
    char s[] = "123";
    permutation(s,s);
    int len=strlen(s);
    combination(s, s,len);
    return 0;
}
*/
void perm(vector<int> &A, int cur_index, const int max_index, vector<vector<int> > &ret)
{
    if(cur_index > max_index)
    {
      ret.push_back(A);
      return;
    }
    for(int i=cur_index;i<=max_index;++i)
    {
        iter_swap(A.begin()+cur_index, A.begin()+i);
        perm(A,cur_index+1,max_index,ret);
        iter_swap(A.begin()+cur_index, A.begin()+i);
    }
}

int main(void)
{
  vector<int> A = {1,2,3};
  const int n = A.size();
  vector<vector< int> > ret;
  perm(A,0,n-1,ret);
  for(int i=0;i<ret.size();++i)
  {
      for(int j=0;j<ret[i].size();++j)
          cout << ret[i][j] << "\t";
      cout << endl;
  }
  return 0;
}
