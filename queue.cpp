#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> myQueue;
	myQueue.push(3);
	myQueue.push(4);
	myQueue.pop();
	cout << "test == 4 right..." << endl;
	while(!(myQueue.empty()))
	{
		cout << myQueue.front() << endl;
		myQueue.pop();
	}

	vector<vector<int> > levels;
	vector<int> level;
	level.push_back(5);
	level.push_back(4);
	levels.push_back(level);
	for(int i = 0 ; i < levels.size(); ++i)
		for(int j = 0; j < levels[i].size() ;++j)
			cout << levels[i][j] << " ";
	level.clear();
	cout << "after clear..." << endl;
	for(int i = 0 ; i < levels.size(); ++i)
		for(int j = 0; j < levels[i].size() ;++j)
			cout << levels[i][j] << " ";



	return 0;
}
