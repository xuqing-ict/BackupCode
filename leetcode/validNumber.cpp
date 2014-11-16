#include <bits/stdc++.h>
using namespace std;


    int f[11][129];
    const int fail = -1;    //非法
    const int st = 0;       //起始
    const int pn = 1;       //正负号
    const int di = 2;       //整数部分
    const int del = 3;      //前面无数字小数点
    const int ddi = 4;      //小数部分
    const int ndel = 5;     //前面有数字小数点
    const int dibl = 6;     //数后空格
    const int ex = 7;       //进入指数
    const int epn = 8;      //指数符号
    const int edi = 9;      //指数数字
    const int finish = 10;     //正确结束
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
