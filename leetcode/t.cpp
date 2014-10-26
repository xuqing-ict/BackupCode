#include<iostream>
#include<ctime>
#include<assert.h>
#include<cstdlib>
#include<cmath>

using namespace std;

    int sqrt(int x) {
		        if(x == 0)return 0;
				        if(x == 1)return 1;
						        double root = x;
								        while(fabs(root*root-x) >= 1e-15)
											        {
														            root = (root*root+x)/(2*root);
																	        }
										        return root;
												    }

int main()
{
	int x = 9;
	cout << sqrt(x) << endl;
	return 0;
}
