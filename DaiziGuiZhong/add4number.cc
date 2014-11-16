#include <bits/stdc++.h>
using namespace std;

bool add4Number_ans(const vector<int> & A, const int  sum)
{
    for(auto a : A)
        for(auto b : A)
            for(auto c: A)
                for(auto d : A)
                    if( a+b+c+d == sum){/*cout << a << " + " << b << " + " << c << " + " << d << " = " << sum << endl; */return true;}
    return false;
}

bool bi_search(const vector<int> &A,const int target)
{
    int l = 0, r = A.size()-1;
    while(l <= r)
    {
        int mid = l + (r-l)/2;
        if(A[mid] == target)  return true;
        if(A[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return false;
}
bool add4Number(const vector<int> & A, const int  sum)
{
    const int  n = A.size();
    vector<int> twoSum(n*n,0);
    int i = 0;
    for(auto a: A)
        for(auto b : A)
            twoSum[i++] = a + b;
    sort(twoSum.begin(),twoSum.end());
  //  for(auto a: twoSum) cout << a << " ";cout << endl;

    for(auto a: twoSum)
        if(bi_search(twoSum,sum-a)) return true;
    return false;
}

int main(void)
{
    //test all cases
    srand(time(nullptr));
    int k = 1000;
    while(k--)
    {
        cout << k << endl;
    int n = rand()%100+10;
    vector<int> A;
    A.resize(n,0);
    for(int i=0;i<n;++i) A[i] = rand()%100;
   // for(auto a : A) cout << a << " ";cout << endl;
    int sum = rand()%1000+9;
  //  cout << " sum = " << sum << endl;
    bool ret1 = add4Number(A,sum);
    bool ans = add4Number_ans(A,sum);
  //  cout << ret1 << " " << ans << endl;
    assert(ans == ret1);
    }

/*

    //one case
    int n = 11;
    vector<int> A = {62,4,48,28,26,34,76,49,34,8,85};

    for(auto a : A) cout << a << " ";cout << endl;
    int sum = 24;
    cout << " sum = " << sum << endl;
    bool ret1 = add4Number(A,sum);
    bool ans = add4Number_ans(A,sum);
    cout << ret1 << " " << ans << endl;
    assert(ans == ret1);
    */
    return 0;
}
