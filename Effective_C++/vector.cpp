#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>vec;
    for(int i = 0 ;i  < 100 ; ++i)
        vec.push_back(i);
    cout << vec.size() << endl; //100
    cout << vec.capacity() << endl; //128
    vec.erase(vec.begin()+10,vec.end()); //�ı���size�����ǲ�δ�ı�capccity
    cout << vec.size() << endl; //10
    cout << vec.capacity() << endl; //128
    vector<int>(vec).swap(vec);
    cout << vec.size() << endl; //10
    cout << vec.capacity() << endl; //10
    vec.clear(); //clear��δ�����ͷſռ䣡����
    cout << vec.size() << endl; //0
    cout << vec.capacity() << endl; //10
    vector<int> (vec).swap(vec); //��������ͷ��˿ռ䣡��
    cout << vec.size() << endl; //0
    cout << vec.capacity() << endl; //0

    unordered_set<char> ex;
    for(int i = 0 ; i < 5; ++i)
        ex.insert(i+'a');
    for(int i = 0 ; i < 5; ++i)
        if( ex.find('a' + i) != ex.end())
            cout << 'a'+i << endl;

    return 0;
}
