/**
 * @file List.cc
 * @brief List.cc
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-10
 */

#include "List.h"
using namespace std;
int main()
{
  vector<int> vec = {6,5,5,4,3,2,1,0,0};
  List  L(vec);
  cout << " L :" ;
  L.print();
  cout << "reverse : " ;
  L.reverse();
  L.print();
  //a1-a2-...-an-b1-b2-...-bn==>a1-b1-a2-b2
  L.permute();
  L.print();
  L.delRepeatNode();
  L.print();
  L.printKNode(6);
  //L.recursivePrintKthNode(3);
  L.partition2(4);
  L.print();


  return 0;
}
