#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <climits>
#include <queue>

#include <time.h>

using namespace std;

static const int X[] = {-1,0,0,1};
static const int Y[] = {0,-1,1,0};
static const long MAX = INT_MAX;

class Orienteering
{
public:
	void main();

private:
	static const int MAX_SIZE = 20;
	int pos_list[MAX_SIZE];
	unordered_map<int, int> pos_2_index;
	long dis[MAX_SIZE][MAX_SIZE];
	int count;

private:
	void BFS(const int x, const int y, const char input[][100], const int row, const int column);
	bool set_dis();
	void output();
	void pre_process();

};

bool Orienteering::set_dis()
{
	int row;
	int column;
	cin >> column;
	cin >> row;
	//assert(row >=0 && row <100);
	//assert(column >=0 && column < 100);
	if (row <= 0 || row > 100 || column <= 0 || column > 100)
	{
		return false;
	}

	char input[100][100] = {0};
	for(int i = 0 ; i < row; ++i)
	{
		for(int j = 0 ; j < column ; ++j)
		{
			cin >> input[i][j];
	
		}
	}

	int cur_index = 1; //S assigned 0
	int end_x = -1;
	int end_y = -1;

	fill_n(pos_list, MAX_SIZE,0);
	fill_n(&dis[0][0], MAX_SIZE*MAX_SIZE,MAX);

	bool s_exist(false), g_exist(false);
	for(int i = 0 ; i < row ; ++i)
	{
		for(int j = 0; j < column; ++j)
		{
			switch(input[i][j])
			{
				case '#':
					break;
				case '.': 
					break;

				case 'G': 
                    if(g_exist) return false;
					end_x = i; 
					end_y = j; 
					g_exist = true;
					break;
				case '@': 
					if(cur_index >= 20)
					{
						return false;
					}
					pos_list[cur_index] = i*column+j;
					pos_2_index.insert(make_pair(i*column+j,cur_index));
                    ++ cur_index;
					break;
				case 'S': 
                    if(s_exist) return false;
					pos_list[0] = i*column+j;
				 	pos_2_index.insert(make_pair(i*column+j,0));
					s_exist = true;
					break;
				//Illegal input
				default: return false;
			}
		}
	}
	//iLLegal input
	if(!s_exist || !g_exist || cur_index >= 20)
	{
		return false;
	}

	count = cur_index + 1;
	pos_2_index.insert(make_pair(end_x*column + end_y,cur_index));
	pos_list[cur_index] = end_x *column + end_y;

	assert(pos_2_index.size() == cur_index+1);

	//compute the dis matirx
	for(int i = 0 ; i < count; ++i)
	{
		int x = pos_list[i]/column;
		int y = pos_list[i]%column;

        
		BFS(x , y , input, row, column);
	}
	return true;
}

void Orienteering::BFS(const int x, const int y,const char input[][100], const int row, const int column)
{
	bool visited[100][100] = {false};

	int start = pos_2_index[x*column + y];
	dis[start][start] = 0;

	int prev_x = x, prev_y = y, prev_pos, prev_index;
	int cur_x, cur_y, cur_pos, cur_index;

	long step = 1;

	queue<int > prev, next;
	prev.push(x*column + y);
	visited[x][y] = true;

	while(!prev.empty())
	{
		while(!prev.empty())
		{
			prev_pos = prev.front(); prev.pop();
			prev_x = prev_pos/column;
			prev_y = prev_pos%column;

			for(int i = 0 ; i < 4 ; ++i)
			{
				cur_x = prev_x + X[i];
				cur_y = prev_y + Y[i];

				cur_pos = cur_x * column + cur_y;
				if (cur_x >= 0 && cur_x < row && cur_y >= 0 && cur_y < column)
				{
					switch(input[cur_x][cur_y])
					{
						case '#':
							break;
						case '.': 
							if (!visited[cur_x][cur_y])
							{
								next.push(cur_pos);
								visited[cur_x][cur_y] = true;
							}
							break;
						case '@': 
							if (!visited[cur_x][cur_y])
							{
								dis[start][pos_2_index[cur_pos]] = step;
								next.push(cur_pos);
								visited[cur_x][cur_y] = true;
							}
							break;
						case 'G':
							if (!visited[cur_x][cur_y])
							{
								dis[start][pos_2_index[cur_pos]] = step;
								next.push(cur_pos);
								visited[cur_x][cur_y] = true;
							}
							break;
						case 'S':
							if (!visited[cur_x][cur_y])
							{
								dis[start][pos_2_index[cur_pos]] = step;
								next.push(cur_pos);
								visited[cur_x][cur_y] = true;
							}
							break;
						default: break;
					}
				}
			}
		}
		prev.swap(next);
		++ step;
	}
}

void Orienteering::output()
{
	for(int i = 1; i < count; ++i)
	{
		if (dis[0][i] == MAX)
		{
			cout << -1 << endl;
			return;
		}
	}
	
	const int len = count;

    vector<vector<long> > f(len,vector<long>( 1<<(len-2),MAX));
	f[0][0] = 0;

	for(int j = 0 ; j < (1 << len-2); ++j)
	{
		for(int i = 0 ; i < len; ++i)
		{
			for(int k = 0 ; k < len-2; ++k)
			{
				if(j & (1<<k))
				{
					f[i][j] = min(f[i][j], dis[k+1][i] + f[k+1][(j&~(1<<k))]);
				}
			}
			f[i][j] = min(f[i][j], f[0][j] + dis[0][i]);
			f[i][j] = min(f[i][j], f[count-1][j] + dis[count-1][i]);
		}
	}
	
	cout << f[count-1][(1<< len-2)-1] << endl;
	return;
}

void Orienteering::main()
{
	pos_2_index.clear();

	if (!set_dis()) {
		cout << -1 << endl;
		return;
	}
	output();
	return ;
}

int main(int argc, char *argv[])
{
	Orienteering o;
	o.main();
	return 0;
}
