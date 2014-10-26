#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class mycompare{
private:
	bool reverse;
public:
	mycompare(const bool & revparam = false)
	{
		reverse = revparam;
	}
	bool operator()(const ListNode* lhs, const ListNode* rhs) const
	{
		if(reverse)
		{
			return (lhs->val > rhs->val);
		}
		else
		{
			return (lhs->val <= rhs->val);
		}

	}

};

int main()
{
	int data[] = {1,5,4,4};
	int n = sizeof(data)/sizeof(int);
	vector<ListNode> vecs(data, data+n);

	typedef priority_queue<ListNode * , vector<ListNode *>, mycompare > Type;

	Type pq(mycompare(true));
	
	for(int i  = 0; i < n; ++i)
	{
		pq.push(&vecs[i]);
	}
	while(!pq.empty())
	{
		cout << (pq.top())->val << endl;
		pq.pop();
	}
	return 0;

}
