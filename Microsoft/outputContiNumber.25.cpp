/*写一个函数,它的原形是 int continumax(char *outputstr,char *intputstr)*/

#include <iostream>
#include <assert.h>

using namespace std;
//outputStr 必须传引用
int continuMax(char * & outputStr, char *inputStr)
{
	int len = 0;
	int ret = 0;
	char *ret_ptr = NULL;
	char *temp = NULL;
	
	if (*inputStr == '\0')
	{
		outputStr = NULL;
		return 0;
	}
	
	char *input_temp = inputStr;
	while(*inputStr)
	{
		char c = *inputStr;
		if (isdigit(c))
		{
			temp = inputStr;
			len = 0;
			while((c = *inputStr) && isdigit(c))
			{
				++len;
				++inputStr;
			}
			if(len > ret)
			{
				ret = len;
				ret_ptr = temp;
				temp = NULL;
			}
		}
		++inputStr;
	}
	if(ret == 0 )
	{
		outputStr = NULL;
		return 0;
	}
	outputStr = new char[ret+1];
	for(int i = 0 ;i < ret; ++i)
	{
		*(outputStr+i) = *(ret_ptr+i);
	}
	*(outputStr + ret) = '\0';
	cout << "ret : " << outputStr << "\t" << ret << endl;
	return ret;
}
int main()
{
	char *a = "1nh234ggv";
	char *out = NULL;
	cout << "ret : " << continuMax(out,a) << endl;
	cout << out << endl;
	return 0;
}
