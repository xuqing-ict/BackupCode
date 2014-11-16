/*请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy*/
#include <bits/stdc++.h>
using namespace std;

char *convert(const char * const s)
{
    int len = strlen(s);    //do not include the '\0'
    if(s == NULL) return NULL;
    int count = 0 ; // record the number of space
    const char *p = s;
    while(*p)
    {
        if(*p == '\t' || *p == ' ') ++count;
        ++p;
    }
    char *ret =  new char[len+count*2+1];
    int j = 0;
    p = s;
    while(*p)
    {
        if(*p == '\0' || *p == ' ') {ret[j++] = '%'; ret[j++] = '2';ret[j++] = '0';}
        else ret[j++] = *p;
        ++p;
    }
    ret[j] = '\0';
    return ret;
}
int main()
{
    char s[1000];
    gets(s);
    char *ret = convert(s);
    cout << ret << endl;
    delete [] ret;
    return 0;
}
