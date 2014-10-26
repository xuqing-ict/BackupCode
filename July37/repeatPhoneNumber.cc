#include <bits/stdc++.h>
using namespace std;

/*
const int N = 100000000;
bitset<N> f;

bool repeatOrNot()
{
    f.reset();
    int number;
    while(cin >>number)
    {
        if(f.test(number))
        {
            cout << "repeat number..." << number << endl;
            break;
        }
        f.set(number);
    }
}
*/

const int N = 100000000;
bool repeatOrNot()
{
    char *f = new char[N/8+1];
    memset(f,0,N);
    int number;
    while(cin >> number)
    {
        int base=number/8, offset=number&7;
        if(f[base]&(1<<offset))
        {
            cout << "repeat number..." << number << endl;
            break;
        }
        f[base]+=(1<<offset);
    }
    delete [] f;
}
//random generate data
void Random()
{
    ofstream out("data.txt");
    const int N = 10000;
    int *data = new int[N];
    for(int i=0;i<N;++i)
        data[i]=i;

    for(int i=0;i<N;++i)
    {
        int j=rand()%N;
        int k=rand()%N;
        swap(data[j],data[k]);
    }

    for(int i=0;i<N;++i)
        out << data[i] << "\t";
    out.close();
    out.clear();
    delete [] data;
}
void bitsetSort()
{
    vector<int> data;
    ifstream in("data.txt");
    int number,i=0;
    while(in >> number)
    {
        data.push_back(number);
    }
    const int N = *max_element(data.begin(),data.end());
    int bytes=N/8+1;
    char *f = new char[bytes];

    fill_n(&f[0],bytes,0);
    for(int i=0; i<N;++i)
    {
        int base=data[i]/8, offset=data[i]&7;
        if(f[base] & (1<<offset)){cout << i <<  " error..." << endl;exit(1);}
        f[base] |= (1<<offset);
    }
    //print result
    ofstream out("sortedArray.txt");
    for(int i=0;i<bytes;++i)
    {
        for(int j=0;j<8;++j)

            if(f[i]&(1<<j))out << i*8+j << "\t";
    }
    out.close();
    out.clear();
    delete [] f;
}

int main(void)
{
    //Random();
    //cout << std::boolalpha << repeatOrNot() << endl;
    bitsetSort();
    return 0;
}
