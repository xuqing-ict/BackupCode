/**
 * @file prime.cc
 * @brief prime
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-08-07
 */

#include <bits/stdc++.h>
using namespace std;

//判定一个数是否是素数O(sqrt(n))

bool isPrime(int n)
{
  if(n == 0 || n == 1) return false;
  for(int k=2; k*k<=n;++k)
  {
    if(n%k == 0 ) return false;
  }
  return true;
}
//枚举所有的约数
vector<int> divisor(int n)
{
    if(n ==0 || n == 1) return vector<int>(1,n);
    vector<int> res;
    for(int i=1; i*i<=n;++i)
    {
      if(n%i==0)
      {
          res.push_back(i);
          if(i!=n/i)res.push_back(n/i);
      }
    }
    return res;
}
//整数分解
map<int,int>prime_factor(int n)
{
  map<int,int> res;
  for(int i=2; i*i <=n;++i)
  {
    while(n%i==0)
    {
      ++res[i];
      n/=i;
    }
  }
  if(n!=1) res[n]++;
  return res;
}
//n以内的素数的个数
int countPrimeLessN(int n)
{
  vector<int> primes;
  if(n == 1) return 1;
  vector<bool> isPrime(n+1,true);
  isPrime[0]=isPrime[1]=false;
  for(int i=2;i<=n;++i)
  {
      if(isPrime[i])
      {
        primes.push_back(i);
        for(int j=2*i;j<=n;j+=i) isPrime[j]=false;
      }
  }
  for(auto a : primes)
      cout << a << "\t";
  cout << endl;
  return primes.size();
}
int main(void)
{
    int n;
    cin >> n;
    cout << isPrime(n) << endl;
    map<int,int> ret = prime_factor(n);
    for(auto a = ret.begin(); a!=ret.end();++a)
        cout << (*a).first <<"\t" << (*a).second << endl;
    vector<int> div = divisor(n);
    for(auto a: div)
        cout << a << "\t";
    cout<< endl;
    cout << countPrimeLessN(n) << endl;
    return 0;
}
