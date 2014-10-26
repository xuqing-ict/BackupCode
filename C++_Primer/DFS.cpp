#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;

string s1 = "AAAAA";
string s2 = "TTTTT";
string s3 = "CCCCC";
string s4 = "GGGGG";

map<int, vector<string> > m;




void produce_input(const vector<int> &merged, vector<string> &ret, int pos , vector<string> &seqs, string index_path, string path)
{
	if (pos == merged.size())
	{
		index_path.resize(index_path.size()-1);
		ret.push_back(index_path);
		return;
	}
	string temp = index_path;
	for(int i = 0 ; i < merged[pos]; ++i)
	{
		index_path += ('0' + i);
		index_path += "_";
		produce_input(merged, ret, pos+1,seqs, index_path,path);
		index_path = temp;
	}

}

void DFS(const vector<int> &merged, vector<string> &indexs, int pos , vector<string> &ret_seqs, string index_path, string & path , vector<string> &adjacent)
{
	//the end
	path += adjacent[pos];
	if (pos == merged.size())
	{
		ret_seqs.push_back(path);

		index_path.resize(index_path.size()-1);
		indexs.push_back(index_path);
		return;
	}
	string temp = index_path;
	string temp_seq = path;
	for(int i = 0 ; i < merged[pos]; ++i)
	{
		index_path += ('0' + i);
		index_path += "_";

		path += m[pos][i];
		DFS(merged, indexs, pos+1, ret_seqs, index_path, path , adjacent);
		index_path = temp;
		path = temp_seq;
	}

}

int main()
{
	vector<string> v0;
	v0.push_back("0_0");
	v0.push_back("0_1");
	m[0] = v0;
	vector<string> v1;
	v1.push_back("1_0");
	v1.push_back("1_1");
	v1.push_back("1_2");
	m[1] = v1;
	vector<string> v2;
	v2.push_back("2_0");
	v2.push_back("2_1");
	v2.push_back("2_2");
	v2.push_back("2_3");
	m[2] = v2;
	vector< string > adjacent ;
	adjacent.push_back(s1);
	adjacent.push_back(s2);
	adjacent.push_back(s3);
	adjacent.push_back(s4);


	vector<int> merged;
	merged.push_back(2);
	merged.push_back(3);
	merged.push_back(4);

	vector<string> ret;
	vector<string> ret_seqs;
	string index_path;
	string path;




	/*
	   produce_input(merged,ret,0,ret_seqs,index_path,path);
	   copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, "\n"));
	   */





	vector<string> indexs;
	DFS(merged, indexs , 0 , ret_seqs, index_path, path, adjacent);
	copy(ret_seqs.begin(), ret_seqs.end(), ostream_iterator<string>(cout, "\n"));

	return 0;
}
