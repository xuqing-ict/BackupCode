#include <bits/stdc++.h>
using namespace std;


    int f[11][129];
    const int fail = -1;    //�Ƿ�
    const int st = 0;       //��ʼ
    const int pn = 1;       //������
    const int di = 2;       //��������
    const int del = 3;      //ǰ��������С����
    const int ddi = 4;      //С������
    const int ndel = 5;     //ǰ��������С����
    const int dibl = 6;     //����ո�
    const int ex = 7;       //����ָ��
    const int epn = 8;      //ָ������
    const int edi = 9;      //ָ������
    const int finish = 10;     //��ȷ����
    void buildDFA()
    {
        memset(f, -1, sizeof(f));
        f[st][' '] = st;
        f[st]['+'] = f[st]['-'] = pn;
        for(int i = '0'; i <= '9'; i ++)
        {
            f[st][i] = f[pn][i] = f[di][i] = di;
            f[del][i] = f[ndel][i] = f[ddi][i] = ddi;
            f[ex][i] = f[epn][i] = f[edi][i] = edi;
        }
        f[di]['.'] = ndel;
        f[st]['.'] = f[pn]['.'] = del;
        f[di][' '] = f[ndel][' '] = f[ddi][' '] = f[dibl][' '] = f[edi][' '] = dibl;
        f[di][0] = f[ndel][0] = f[dibl][0] = f[ddi][0] = f[edi][0] = finish;
        f[di]['e'] = f[ndel]['e'] = f[ddi]['e'] = ex;
        f[ex][' '] = ex;
        f[ex]['+'] = f[ex]['-'] = epn;
    }
    bool DFA(const char *s)
    {
        int situ = st;
        for(int i = 0;; i ++)
        {
            situ = f[situ][s[i]];
            if(situ == finish) return true;
            if(situ == fail) return false;
        }
        return true;
    }
    bool isNumber(const char *s) {
        buildDFA();
        return DFA(s);
    }
int main()
{
    cout << isNumber ("-.23") << endl;
    return 0;
}
