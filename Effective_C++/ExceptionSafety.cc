/**
 * @file ExceptionSafety.cc
 * @brief  expection safety
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-14
 */

//do not run!!
#include <bits/stdc++.h>
using namespace std;


class prettyMenu
{
public:
  prettyMenu():imageChangesl(0){
    bgImage = new int(0);
  }
  void changeBackGroung(std::istream &imgsrc);
private:
  mutex m;
  Image * bgImage;
  int imageChanges;

};
//此版本的change函数没有提供任何异常安全性的保证
void prettyMenu::changeBackGroung(std::istream &imgsrc)
{
  lock(&m);
  delete bgImage;
  ++imageChanges;
  bgImage =  new Image(imgsrc);//如果此处抛出异常，互斥器资源泄漏
  //并且bgImage指向已删除的对象，并且imegeChanges已经加1
  unlock(m);
}
//解决资源泄漏使用“对象管理资源”
//对于数据的败坏：
//法一：
class prettyMenu
{
std::shared_ptr<Image> bgImage;
};

void prettyMenu::changeBackGroung(std::istream &imgsrc)
{
  Lock l(&m); //以对象管理资源
  bgImage =  bgImage(new Image(imgsrc));
  ++imageChanges;
}
//将对象内的所有的对象移到另一个对象中，并且赋予原对象一个指针
struct PMImmpl
{
std::shared_ptr<Image> bgImage;
int imageChanges;
};
class prettyMenu
{
private:
  mutex m;
  std::shared_ptr<PMImpl> pImpl;
};
void prettyMenu::changeBackGroung(std::istream &imgsrc)
{
  using std::swap;
  Lock l(&m); //以对象管理资源
  std::shared_ptr<PMImpl> pNew = (new PMImpl(*pImpl)); //创建一个临时的对象，并在处理完毕之后，与原对象交换
  pNew->bgImage.reset(new Image(imgSrc));
  ++pNew->imageChanges;
  swap(pImpl, pNew);
}

int main()
{
  prettyMenu pm;
  pm.changeBackGroung("1234");
  return 0;
}
