#include<iostream>
#include<string>
using namespace std;

int BF(string S, string T)
{
	int lenS = S.length();
	int lenT = T.length();
	int i = 0 , j = 0 , pos = -1;
	while(i <= (lenS - lenT))
	{
		while((i <= (lenS - lenT )) && (S[i] != T[j])){ i++, j = 0 ;}
		if (S[i] == T[j]) pos = i;
		while((i < lenS) && S[i] == T[j]){ i++, j++;}
		if(j == lenT)return pos;
	}
	return -1;
}


int main()
{
	string S = "123456";
	string T = "123456";
	cout << T << " at " << S << "\t" << BF(S,T) << "-th pos." << endl;
}
