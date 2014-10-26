
#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <iterator>
#include <numeric>
using namespace std;

const int size = 3;
const string DELIM_OF_READ = "IDMS^\t\n";
const string DELIM_OF_REF = "ACGTN^\t\n	";

struct test
{
	vector<vector<int> > a;
	test():a(size,vector<int>(size, 0)){}
};

// int to string
string int2Str(int number)
{
	char temp[10];

	bool flag = false;

	if(number < 0)
	{
		number = -number;
		flag = true;
	}

	int digits = 0;
	int t_number = number;
	do
	{
		digits++;
		t_number /= 10;
	}while(t_number);

	int index = 0;
	if(flag)
	{
		temp[index++] = '-';
	}

	for(int i = digits+index-1; i >= index ; --i )
	{
		temp[i] = (char)(number%10 + '0');
		number/=10;
	}
	temp[digits+index] = '\0';

	return string(temp);

}

void find_max_common_seq(
		const string &s,
		const string &t,
		string &cigar1,
		string &quality_)
{
	cout << "ref = " << s << endl;
	cout << "read= " << t << endl;

	assert(!s.empty() && !t.empty());
	int row = s.size() + 1;
	int column = t.size() + 1;
	cout << "rwo = " << row << " column = " << column << endl;

	vector<vector<int> > matrix(row, vector<int>(column,0));
	vector<vector<int> > back_track(row, vector<int>(column,-1));

	for(int i = 0; i < row-1 ; ++i)
	{
		for(int j = 0; j < column-1; ++j)
		{
			if (s[i] == t[j])
			{
				matrix[i+1][j+1] = matrix[i][j]+1;
				back_track[i+1][j+1] = 1;
			}
			if (matrix[i+1][j+1] < matrix[i+1][j])
			{
				matrix[i+1][j+1] = matrix[i+1][j];
				back_track[i+1][j+1] = 2;
			}
			if (matrix[i+1][j+1] < matrix[i][j+1])
			{
				matrix[i+1][j+1] = matrix[i][j+1];
				back_track[i+1][j+1] = 0;
			}
			//			matrix[i+1][j+1] = max(max(matrix[i+1][j+1], matrix[i+1][j]), matrix[i][j+1]);
		}
	}
	for(int i = 0; i < row ; ++i)
	{
		for(int j = 0; j < column; ++j)
		{
			//cout << matrix[i][j] << " ";
			printf("%2d ",matrix[i][j]);
		}
		cout << endl;
	}
	for(int i = 0; i < row ; ++i)
	{
		for(int j = 0; j < column; ++j)
		{
			//cout << matrix[i][j] << " ";
			printf("%2d ",back_track[i][j]);
		}
		cout << endl;
	}
	cout << "end..." << endl;
	int i = row-1;
	int j = column-1;
	int ins = 0;
	int del = 0;
	int match = 0;
	vector<int> path(t.size()+2 , -1);
	string ret;
	while(back_track[i][j] != -1)
	{
		cout << "debug..." << endl;

		if (back_track[i][j] == 0)
		{
			//ret += 'D';
			//path[j] = i-1;
			--i;
		}
		else if (back_track[i][j] == 1)
		{
			//ret += 'M';
			path[j] = i;
			--i;--j;
		}
		else
		{
			//ret += 'I';
			//path[j] = i;
			--j;
		}
	}
	cout << path.size() << endl;
	cout <<	s << endl;
	cout <<	t << endl;
	cout << "ret = " << ret.size() << " " << ret << endl;
	std::reverse(ret.begin(), ret.end());

	// generate quality sequence
	int left(0), right(0); // denote -1's interval
	int minus_one_count(0), match_count(0);
	string cigar;


	// boundary treatment
	path[0] = 0; 
	// sentinel element 
	path[path.size()-1] = path.size() - 1;

	copy(path.begin(), path.end(),ostream_iterator<int>(cout," "));
	cout << endl;

	i = 1;
	match_count = 0;
	while(i < path.size() - 1)
	{
		// STEP 1: deal with [positive numbers] in path 
		while(i < path.size() - 2 && path[i] != -1 && path[i+1] == path[i] + 1)
		{
			++ match_count;
			++ i;
		}
		if(i == path.size() - 2)
		{
			++ match_count;
			cigar += int2Str(match_count) + 'M';
			break;
		}
		else if(path[i] != -1 &&  path[i+1] != -1 && path[i+1] != path[i] + 1)
		{
			++ match_count;
			cigar += int2Str(match_count) + 'M';
			match_count = 0;

			cigar += int2Str(path[i+1] - path[i] - 1) + 'D';
			++ i;
			continue;
		}
		else if(path[i] != -1 && path[i+1] == -1)
		{
			++ match_count;
			++ i;
		}

		// STEP 2: deal with [-1 -1 ... -1]
		// [left+1, right-1] = {-1, -1 ,,,,-1}
		left = i-1;
		while(++i < path.size() -1  && path[i] == -1)
			;
		right = i;

		int delta = (path[right] - path[left] - 1) - (right-left-1);

		// case 1: match
		if(delta == 0)
		{
			//cigar += int2Str(match_count + delta) + 'M';
			++ match_count;
		}
		// case 2:  mismatch + delete
		else if(delta > 0)
		{
			if(right-left+1 + match_count > 0)
				cigar += int2Str(right-left-1 + match_count) + 'M';

			if(right != path.size() - 1)
				cigar += int2Str(delta) + 'D';

			match_count = 0;
		}
		// case 3: mismatch + insert
		else
		{
			if(path[right]-path[left]-1+match_count > 0)
				cigar += int2Str(path[right]-path[left]-1 + match_count) + 'M';

			if(right != path.size() - 1)
				cigar += int2Str(-delta) + 'I';

			match_count = 0;
		}

	}

	cout << "cigar: " << cigar << endl;

	string quality;

	// separator

	int tail = cigar.find_first_of(DELIM_OF_READ);

	//find quality
	int cur_type_base_count = 0;
	char map_type;
	int count = 0;
	int start = 0;
	int k = 0;

	// index of string s and t
	i = 0; j = 0;

	while(tail != string::npos)
	{
		map_type = cigar[tail]; 
		cur_type_base_count = atoi(cigar.substr(start,tail-start).c_str());
		cout << "DEBUG = " << cur_type_base_count << endl;

		if (map_type == 'M')
		{
			k = 0;
			while(k < cur_type_base_count)
			{
				if (s[i] == t[j])
				{
					++ count;
				}
				else
				{
					if(count > 0){
						quality += int2Str(count);
						cout << count << endl;
						count = 0;
					}
					quality += s[i];
				}
				++i;++j;++k;
			}
			/*
			   if(count > 0){
			   quality += int2Str(count);
			   cout << count << endl;
			   count = 0;
			   }*/
		}
		else if (map_type == 'D')
		{		
			if(count > 0){
				quality += int2Str(count);
				cout << count << endl;
				count = 0;
			}

			quality += '^';

			for(k = 0; k<cur_type_base_count; ++k, ++i)
			{
				quality += s[i];
			}
		}
		else if (map_type == 'I')
		{
			j += cur_type_base_count;
		}
		else
		{
			//do nothing
		}

		start = tail+1;
		tail = cigar.find_first_of(DELIM_OF_READ, start);
	}
	if(count > 0){
		quality += int2Str(count);
		cout << count << endl;
		count = 0;
	}


	cout << "quality: " << quality << endl;

	/*
	   i = 0;
	   int n = path.size();
	   cout << "n = " << n << endl;
	   string TEST;

	   while(i < n && path[i] == -1) ++i;
	   cout << " i = " << i << endl;

	   while(i < n)
	   {
	//	cout << "debug..." << endl;
	int start = i;
	while(i < (n - 1) && path[i+1] == path[i] +1)
	{
	++i;
	}
	int end = i;

	stringstream ss;
	ss << (end-start+1);
	TEST += ss.str();
	TEST += 'M';
	cout << "TEST = " << TEST << endl;

	if (i < n-1)
	{
	if (path[i+1] > path[i]+1)
	{
	stringstream ss;
	ss << (path[i+1]-path[i]-1);
	TEST += ss.str();
	TEST += 'D';
	cout << "TEST = " << TEST << endl;
	++i;
	}
	if(path[i+1] == path[i])
	{
	start = i;
	while(i < n - 1 && path[i+1] == path[i])
	{
	++i;
	}
	if (i == n-1)
	{
	end = i+1;

	}
	else
	{
	end = i;
	}
	stringstream ss;
	ss << (end - start);
	TEST += ss.str();
	TEST += 'I';
	cout << "TEST = " << TEST << endl;
	}

	}
	++i;

	}
	cout << "TEST = " << TEST << endl;

	cigar = TEST;

	const string DELIM_OF_READ = "IDMS^\t\n";
	int tail = cigar.find_first_of(DELIM_OF_READ);

	//find quality
	int cur_type_base_count = 0;
	char map_type;
	quality;
	i = 0,j = 0;
	int count = 0;
	int  k = 0;
	int start = 0;

	while(tail != string::npos)
	{
		cur_type_base_count = atoi(cigar.substr(start,tail-start).c_str());
		cout << "DEBUG = " << cur_type_base_count << endl;
		map_type = cigar[tail]; 
		if (map_type == 'M')
		{
			int k = 0;
			while(k < cur_type_base_count)
			{
				if (s[i] == t[j])
				{
					//++count;
					quality += '1';
				}
				else
				{
					quality += s[i];
				}
				++i;++j;++k;
			}
			//quality += '\t';
		}
		else if (map_type == 'I')
		{
			j += cur_type_base_count;
		}
		else if (map_type == 'D')
		{
			quality += '^';
			k = 0;
			while(k < cur_type_base_count)
			{
				quality += s[i+k];
				++k;
			}
			i += cur_type_base_count;
		}
		else
		{
			//do nothing
		}

		start = tail+1;
		tail = cigar.find_first_of(DELIM_OF_READ, start);
	}

	cout << "DEBUG!!!" << endl;
	cout << "quality = " << quality << endl;
	cout << "quality.size() = " << quality.size() << endl;

	i = 0;
	ret.clear();

	while(i < quality.size())
	{
		if (quality[i] == '1')
		{
			int count = 0;
			while( i < quality.size() && quality[i] == '1')
			{
				++count;
				++i;
			}
			stringstream ss;
			ss << count;
			ret += ss.str();
			if (i == quality.size())
			{
				break;
			}
		}
		else
		{	
			ret += quality[i];
			++i;
		}
	}

	cout << "ret  = " << ret << endl;
	*/
}

const int A = 0;
const int T = 1;
const int C = 2;
const int G = 3;
const int N = 4;

int error_read_count = 0;
int base_counts[5] = {0};
int del_pos[36] = {0};
int del_len[36] = {0};

int ins_pos[36] = {0};
int ins_len[36] = {0};
int error_pos[36] = {0};

int error_types[5][5] = {0};

void print()
{
	cout << "error_read_count : " << error_read_count << endl;

	cout << "base_count : " << endl;

	for(int i = 0; i < 5 ;++i)
	{
		cout << i << " " << base_counts[i] << endl;
	}

	cout << "error_pos : " << endl;
	for(int i = 0; i < 36 ;++i)
	{
		cout << i << " " << error_pos[i] << endl;
	}
	cout << "del pos :" << endl;
	for(int i = 0 ; i < 36 ; ++i)
	{
		cout << del_pos[i] << " ";
	}
	cout << endl;
	cout << "del len :" << endl;
	for(int i = 0 ; i < 36 ; ++i)
	{
		cout << del_len[i] << " ";
	}
	cout << endl;
	cout << "ins pos :" << endl;
	for(int i = 0 ; i < 36 ; ++i)
	{
		cout << ins_pos[i] << " ";
	}
	cout << endl;
	cout << "ins len:" << endl;
	for(int i = 0 ; i < 36 ; ++i)
	{
		cout << ins_len[i] << " ";
	}
	cout << endl;


	for(int i = 0 ; i < 5 ; ++i)
	{
		for(int j = 0 ; j < 5 ; ++j)
		{
			cout << error_types[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void update_error_type()
{
	string read = "AACACCCTAAAATCTTTACTGCCATATTCACCCCAC";

	int cur_read_len = read.size();
	
	cout << "!!!!!!!!!!!!!!!!1" << endl;

	for(int i = 0; i < cur_read_len;++i)
	{
		switch(read[i])
		{
			case 'A':
				base_counts[A]++;break;
			case 'T':
				base_counts[T]++;break;
			case 'C':
				base_counts[C]++;break;
			case 'G':
				base_counts[G]++;break;
			default:
				base_counts[N]++;break;
		}
	}
	copy(base_counts, base_counts+5, ostream_iterator<int>(cout,"\t"));
	cout << endl;

	//string no_error_MD( "MD:Z:");
	string no_error_MD(int2Str(cur_read_len));
	cout << "no_error_MD = " << no_error_MD << endl;

	string ref_qual = "0T6G27";
	cout << "ref_qual = " << ref_qual << endl;

	if (ref_qual == no_error_MD)
	{
		return;
	}
	else
	{
		++error_read_count;
	}

	int ref_qual_len = ref_qual.size();
	//bool f_or_r = ((atoi(sam_info_1[LABEL].c_str()) >> 4) & 1)?true:false;
	bool f_or_r = false;

	string read_qual = "4M1I31M";
	cout << "read_qual = " << read_qual << endl;

	//ref_pos and read_pos is the cur pos of ref_seq and read
	int ref_pos = 0; // record the map pos 
	int read_pos = 0;

	int start = 0;

	char map_type;
	int cur_type_base_count = 0;

	//record inserts of each pos in read 
	vector<int> inserts_in_each_pos(cur_read_len, 0 );
	int tail = read_qual.find_first_of(DELIM_OF_READ);

	while(tail != string::npos)
	{
		cur_type_base_count = atoi(read_qual.substr(start,tail-start).c_str());
		cout << "NUM = " << cur_type_base_count << endl;

		map_type = read_qual[tail];

		if(map_type == 'M')
		{
			read_pos += cur_type_base_count;
			ref_pos += cur_type_base_count;
		}
		else if (map_type == 'I' || map_type == 'S')
		{
			if (f_or_r)
			{
				++(ins_pos[cur_read_len - read_pos - 1]);
				++(ins_len[cur_type_base_count-1]);
			}
			else
			{
				++(ins_pos[read_pos]);
				++(ins_len[cur_type_base_count]);

			}
			inserts_in_each_pos[read_pos] = cur_type_base_count;
			read_pos += cur_type_base_count;
		}
		else if (map_type == 'D')
		{
			//reverse
			if(f_or_r)
			{
				++del_pos[cur_read_len - read_pos + 1];
				++del_len[cur_type_base_count];
			}
			else
			{
				++del_pos[read_pos];
				++del_len[cur_type_base_count];
			}
		}
		else
		{
			//nothing
		}
		start = tail+1;
		tail = read_qual.find_first_of(DELIM_OF_READ, start);

	}
	
	copy(inserts_in_each_pos.begin(), inserts_in_each_pos.end(),ostream_iterator<int>(cout," "));
	cout << endl;

	//quality
	cur_type_base_count = 0;
	ref_pos = 0;
	read_pos = 0;
	start = 0;
	tail = ref_qual.find_first_of(DELIM_OF_REF);
	
	cout << ref_qual << endl;

	while(tail != string::npos)
	{
		cout << ref_qual.substr(start, tail-start) << endl;
		cur_type_base_count = atoi(ref_qual.substr(start,tail-start).c_str());
		map_type = ref_qual[tail];

		if (map_type == '^')
		{
			cout << "^ = " << cur_type_base_count << endl;

			for(int i = tail; i < ref_qual_len ; ++i)
			{
				if (ref_qual[i] == 'A' ||
						ref_qual[i] == 'T' ||
						ref_qual[i] == 'C' ||
						ref_qual[i] == 'G' || 
						ref_qual[i] == 'N')
				{
					++tail;
				}
				else
				{
					break;
				}
			}
		}
		else if (map_type == 'A' || 
				map_type == 'T' ||
				map_type == 'C' ||
				map_type == 'G' ||
				map_type == 'N')
		{
			cout << map_type << " M = " << cur_type_base_count << endl;

			read_pos += cur_type_base_count;

			int cur_inserts_count = accumulate(inserts_in_each_pos.begin(), 
					inserts_in_each_pos.begin() + read_pos, 0);
			
			cout << "cur_insert_count = " << cur_inserts_count << endl;

			char to = read[cur_inserts_count + read_pos];

			//reverse
			if(f_or_r)
			{	
				++(error_pos[cur_read_len - read_pos - 1]);
			}
			else
			{
				cout << read_pos << endl;
				++(error_pos[read_pos]);
			}
			int f, t;
			switch(map_type)
			{
				case 'A': f = A; break;
				case 'T': f = T; break;
				case 'C': f = C; break;
				case 'G': f = G; break;
				default:  f = N; break;
			}
			switch(to)
			{
				case 'A': t = A; break;
				case 'T': t = T; break;
				case 'C': t = C; break;
				case 'G': t = G; break;
				default:  t = N; break;
			}


			cout << read << "\t" << cur_inserts_count + read_pos << endl;
			cout << map_type << " " << to << endl;
			cout << f << " " << t << endl;

			if(f == t)
			{
				//do nothing
			}
			else
			{
				++(error_types[f][t]);
			}
			++read_pos;
		}

		start = tail+1;
		tail = ref_qual.find_first_of(DELIM_OF_REF, start);
	}
	print();
	return;
}

int main()
{
	int count = 12;
	stringstream ss;
	ss <<  count;
	cout << "ss = " << ss.str() << endl;

	//		string ref =  "AGACCATCAATCGCTGGCTGGCCGAAGCAGGCGTCATCG";
	//		string read = "AGACCATCAATCGCTGGCTGCCGAAGCAGGCGTCAT";
//		string read = "AACACCCTAAAATCTTTACTGCCATATTCACCCCAC";
//			string ref = "TACACCTGAAATCTTTACTGCCATATTCACCCCACA";

	//		string ref =  "TGCGTATTCACTGCATGCAGCATTGGTACAACCTGAGTC";
	//		string read = "TACGCATTCACTGCATGCAGCATTGGACAAACTGAG";
//			string ref = "ACGGTATCTGATGGCCACGGGATTGGTGCGC";
//			string read ="ACGGAACGGTATCTGATGGCCACGGGATTGGTGCGC";

	string ref  = "GGATGCAGATGTGGCTGCTGATTGTAGTGACGCTGA";
	string read = "GGATGCAGATGTGGCTGCTGGTTGTAGTGACAGCTG";
	string cigar, quality;
	find_max_common_seq(ref,read,cigar, quality);
	/*
	   cout << read << endl;
	   cout << ref << endl;
	   cout << cigar << endl;
	   cout << quality << endl;*/
	test t;
	for(int i = 0 ; i < size ; ++i)
	{
		for(int j = 0 ; j < size ; ++j)
			cout << t.a[i][j] << " " ;
		cout << endl;
	}
	
	update_error_type();
}



