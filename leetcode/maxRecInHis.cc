   #include <bits/stdc++.h>
   using namespace std;

   int largestRectangleArea(vector<int> &height) {
        const int n = height.size();
        if( n < 1) return 0;
        vector<int> left,right;
        left.resize(n);
        right.resize(n);

        stack<int> s;
        for(int i=0; i<n; ++i)
        {
            while(!s.empty() && height[s.top()] >= height[i])
            {
                s.pop();
            }
            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        stack<int>().swap(s); //clear

        for(int i=n-1; i>=0; --i)
        {
            while(!s.empty() && height[s.top()] >= height[i])
            {
                s.pop();
            }
            right[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }

        int ret = 0;
        for(int i=0;i<n;++i)
        {
            ret = max(ret,(right[i]-left[i]-1)*(height[i]));
        }
        return ret;
   }
   int main(void)
   {
       vector<int> A = {999,999,999,999};
       cout << largestRectangleArea(A) << endl;
        return 0;

   }
