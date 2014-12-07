/**
 * @file Trie.cc
 * @brief Trie tree
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-07-28
 */

#include "Trie.h"
using namespace std;

int main(void)
{
    string  file;
    cin >> file;
    Trie tr;
    tr.build(file);
    cout << std::boolalpha << tr.search("abc") << endl;
    cout << std::boolalpha << tr.search("ae") << endl;
    tr.insert("ae");
    cout << std::boolalpha << tr.search("ae") << endl;
    return 0;
}
