#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };


    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
       int n = intervals.size();
        vector<Interval> ret;
        if(n==0 )
        {
            ret.push_back(newInterval);
            return ret;
        }
        int new_start = -1, new_end = -1;
        bool label = false;
        int beg = -1;

        int  i = 0;

        //特殊处理变态的输入！！！
        if(newInterval.end < intervals[0].start)
        {
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        if(newInterval.start > intervals[n-1].end)
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        while(i < n && ( intervals[i].start < newInterval.start && intervals[i].end < newInterval.start))
        {
            ret.push_back(intervals[i]);
            ++i;
        }

        if(intervals[i].start <= newInterval.start)
        {
            new_start = intervals[i].start;
            beg = i;
        }
        else
        {
            new_start = newInterval.start;
        }

        //insertion the end
        while(i < n && intervals[i].end < newInterval.end)
        {
            ++i;
        }

        if(i == n)
        {
            new_end = max(newInterval.end , intervals[n-1].end);
            ret.push_back(Interval(new_start, new_end));
            return ret;
        }
        else
        {
            if(intervals[i].start > newInterval.end)
            {

                new_end = newInterval.end;
                ret.push_back(Interval(new_start, new_end));
            }
            else
            {
                new_end = intervals[i].end;
                ret.push_back(Interval(new_start, new_end));
                ++i;
            }
            //++i;
            while(i < n)
            {
                ret.push_back(intervals[i]);
                ++i;
            }
        }

        return ret;

    }
        vector<Interval> insert2(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        //由于中间会删除元素，因此size操作失效
        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end())
        {
            if(newInterval.start > it->end)
            {
                ++it;
                continue;
            }
            else if(it->start > newInterval.end)
            {
                intervals.insert(it, newInterval);
                return intervals;
            }
            else
            {
                cout << "xq" << endl;
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
                //返回的是删除位置后面的迭代器
                it = intervals.erase(it);
            }
        }
        //如果在上面没返回的话，那么现在newInterval应该是最右边的interval了，插入之
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }




  inline bool myFunc(const Interval &lhs, const Interval &rhs)
    {
        return lhs.start < rhs.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty()) return intervals;

        sort(intervals.begin(), intervals.end(), myFunc);

        cout << "after sorting... " << endl;

        for(int i = 0; i < intervals.size(); ++i)
            cout << intervals[i].start << "\t" << intervals[i].end << endl;

        vector<Interval > ret;

        vector<Interval>::iterator it = intervals.begin();
        int left = intervals[0].start, right = intervals[0].end;
        while(1)
        {
            ++it;
            if(it == intervals.end()) break;

            if( it->start > right)
            {
                ret.push_back(Interval(left,max(right, (*(it-1)).end)));
                left = it->start;
                //记录下一个要插入区间的头，end为下一个要插入区间的候选的尾巴
                //right = it->end;
            }
            right = max(right,it->end);
        }
        ret.push_back(Interval(left,max(right, (*(intervals.end()-1)).end)));
        return ret;
    }

    int lengthOfLastWord(const char *s) {
        if(s == NULL || *s == '\0') return 0;
        const char *record = s;
        int ret = 0;
        while(1)
        {
            //if((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
            if(isalpha(*s))
            {
                ++s;
                cout << "++" << s-record << endl;
            }
            else
            {
                assert(*s == '\t' || *s == ' ' );
                if(s-record > 0)
                    ret = s-record;
                ++s;
                record = s;
            }
            if(*s == '\0')
            {
                if(s-record > 0)
                    ret = s-record;
                cout << "here " << s-record << endl;
                break;
            }
        }
        return ret;
    }
        bool canJump(int A[], int n) {
        if(n == 0) return true;

        int sum = 0;

        int  i = 0;
        while(i < n)
        {
            if(A[i] != 0)
            {
                i+= A[i];
            }
            else
            {
                break;
            }
        }

        if(i >= n-1) return true;
        return false;
        }

    int main()
    {
        Interval iv1(1,5),iv2(0,1);//iv3(2,5);
        vector<Interval> vecs;
        vecs.push_back(iv1);
       // vecs.push_back(iv2);

        vector<Interval> ret  = insert2(vecs,iv2);
        for(int i = 0 ; i < ret.size(); ++i)
        {
            cout << ret[i].start << "\t" << ret[i].end << endl;
        }
        vector<int> a;
        a.push_back(1);
        a.push_back(2);

        vector<Interval> vecs2;
        vecs2.push_back(Interval(1,4));
        vecs2.push_back(Interval(0,2));
        vecs2.push_back(Interval(3,5));

        ret= merge(vecs2);
        for(int i = 0 ; i < ret.size(); ++i)
        {
            cout << ret[i].start << "\t" << ret[i].end << endl;
        }
        char A[] = "12345";
        char *c = A+3;
        cout << c-A << endl;
        const char *s = "b  a   ";
        cout << lengthOfLastWord(s) << endl;
        int data[] = {3,7,0,0,0,0};
        if(canJump(data,6))
            cout << "YES..." << endl;
        else
            cout << "NO..." << endl;
        return 0;
    }
