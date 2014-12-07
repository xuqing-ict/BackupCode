/**
 * @file Trace.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-28
 */

#include <iostream>
#include <string>
using namespace std;

int increment(int x)
{
    return x+1;
}

class Trace
{
public:
    inline Trace(const string &_name):name(_name){
        if(active)
            cout << "enter function " << name << "..." << endl;
    }
    inline ~Trace()
    {
        if(active)
            cout << "exit..." << endl;
    }
    inline void debug(const string &msg)
    { 
       if(active)
            cout << msg << endl;
    }

private:
    string name;
    static bool active;   
};

bool Trace::active = true;
int increment2(int x)
{
    string name = "increment2";
    Trace t(name);
    t.debug("enter...");
    return x+1;
}

int main(void)
{
    int x = 0;
    clock_t start,finish;
    double total=0;
    start = clock();
    for(int i=0;i<1000000;++i)
        increment2(x);
    finish = clock();
    total = static_cast<double>(finish-start)/CLOCKS_PER_SEC;
    start = clock();
    for(int i=0;i<100000000;++i)
        increment(x);
    finish = clock();
    total = static_cast<double>(finish-start)/CLOCKS_PER_SEC;
    cout << "running time = " << total << " s." << endl;
    cout << "running time = " << total << " s." << endl;
    return 0;
}
