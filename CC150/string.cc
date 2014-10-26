// Last Update:2014-06-08 17:36:00
/**
 * @file string.cpp
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-08
 */

#include <bits/stdc++.h>
using namespace std;

void ReplaceBlank(char str[], int length)
{
  if(str == NULL || length <= 0) return;
  int count = 0;
  int chars = 0;
  int i = 0;
  while(*(str+i) )
  {
    if(*(str+i) == ' ') ++count;
    ++chars;
    ++i;
  }
  if(chars + 2*count > length)
  {
    cout << "over the length!!!" << endl;
    return ;
  }

  char *second = str + (chars + 2*count);
  *second-- = '\0';
  char *first = str + chars -1;
  for(int i = chars-1; i >= 0 ; --i)
  {
    if(str[i] == ' ') {*(second--) = '0'; *(second--) = '2';*(second--) = '%';first--;}
    else *(second--) = *(first--);
  }
  
}
void merge(int a[], int b[], int m ,int n)
{
  cout << m << " " << n << endl;
  if(n == 0) return ;
  int index_a = m-1, index_b = n-1;
  int i = m + n - 1;
  while(i >= 0 && index_a >= 0 && index_b >= 0)
  {
    if(a[index_a] > b[index_b]) 
    {
      a[i--] = a[index_a--];
    }
    else
    {
      a[i--] = b[index_b--];
    }
  }
  //while(index_a >= 0 ) a[i--]  = a[index_a--];
  while(index_b >= 0 ) a[i--] = b[index_b--];
}
int main()
{
  char str1[] = "Hello World"; //size = 12
  char str2[] = "Hello World"; //size = 12
  cout << strlen(str1)  << endl;
  assert(str1 != str2);
  const char *s1 = "Hello";//常量数组只用一份拷贝在内存中
  const char *s2 = "Hello";
  cout << strlen(s1)  << endl;
  assert(s1 == s2);
  char str[100] = "   ";
  int n = sizeof(str)/sizeof(char);
  cout << str << endl;
  ReplaceBlank(str, n);
  cout << str << endl;
  int a[100] = {1,3,5,7,89,90,880};
  int b[] = {4,8,9,1000};
  int m = 7, n2 = sizeof(b)/sizeof(int);
  merge(a,b,m,n2);
  for(int i = 0 ; i < 100; ++i)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
