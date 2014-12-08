title: over-eager evaluation
date: 2014-12-07 21:03:15
categories: Python

tags: Python 面向对象
---
Python之面向对象

<!--more-->

#### 在C++和Python中，都有面向对象的概念，但是两者有哪些重要的区别呢？用最简单的语言便是，C++把每一个用户（这里当然值的是使用代码的程序员）当做是潜在的可能的犯罪分子，可以提供给你的部分已经规定好了，不可逾越。Python则是个比较柔和的管理方式，它认为所有的用户都具有高度的自觉性，用户可以很自自觉的使用代码。更加生动的比喻见[这里](http://blog.csdn.net/shoulinjun/article/details/38150335 "title")

### 类与对象

#### 在Python中，类由关键字class定义，例如下面的代码：

```
class Student(object): 
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def display(self):
        print "%s : %s"  %(self.__name, self.__score)
    def
```

#### 关于上述代码的几点说明：
+ 在Python中的类如果没有父类，一般建议继承object类，如果有父类，则写在类名后的括号内，例如： ** class Student (Person) **, Student类继承自Person类。
+ \__init__相当于构造函数，这里定义实例的方式是 s = Student(“Tom”,100) 
+ self 关键字，其实就类似于C++中的this指针，只是在C++中，我们一般不写出，但是this参数还是有的，这里的self必须明确的写出来，这就意味着 **类的函数的第一个参数必须是self**。
+ 虽然函数的第一个参数是self，但是我们在调用相应的函数时，不需要提供self接受的参数。比如上述的display函数，可以直接使用  s.display() 即可。
+ 类内部的成员变量是在  \__init__ 函数中定义的。 使用 ** self\.变量名 **  来定义内部的变量。
+ 但是，变量的定义绝不仅限于此，可以使用类的实例定义其他的成员变量，这就会导致 ** 统一各类的不同的实例会由不同的成员变量**。

### 关于私有变量的定义
#### 上面已经提到了，Python并未有任何强制性的措施使得不能访问私有变量。但是约定俗成的是  **__变量名__** 或 **__函数名__** 来声明私有变量以及私有的函数。例如改写上面的Student得到下面的代码：
```
class Student(object):
    def __init__(self, name, score):
        self.__name = name
        self.__score = score
    def display(self):
        print "%s : %s"  %(self.__name, self.__score)
    #get
    def get_score(self): return self.__score
    def get_name(self): return self.__name
    #set
    def set_score(self,score): 
        if not isinstance(score,int): 
            raise ValueError("bad score!!!")
        if 0 <= score <= 100:
            self.__score = score
        else:
            raise ValueError("invalid number!!!")

    def set_name(self,name): 
        if not isinstance(name, str):
            raise ValueError("bad name...")
        self.__name = name

    def level(self,score):
        if 90 <= self.__score <= 100:
            print "A"
        elif self.__score > score:
            print "B"
        else:
            print "C"
```

####几点说明： 例如有  ： sa = Student()
+ 上述代码中的 __name 和 __score 是私有变量。当我们试图 sa.__name 时，会收到提示说该属性不存在，虽然使用sa.Student__name可以访问，但是这样的name mangling的方式不是所有的编译器一定都兼容的。因此强烈不推荐。
+ 我们可以使用get以及set函数来执行相应的访问以及修改的功能。
+ 使用set来更新成员变量，我们可以检查传入参数的合法性，使用isinstance 以及 排除不合理的值。比如上述的 score 大于100 或者 小于 0， 或者说不是整数，这时候抛出**ValueError异常**。

### 下面是Python OO 之 继承与多态
#### 首先，继承很简单，比如下面的代码：
#### Animal 是基类。 Dog 以及 Cat 继承自 Animal。

```
class Animal(object):
    def run(self):
        print "Animal is running..."

class Dog(Animal):
    def run(self):
        print "Dog is running..."
    def eat(self):
        print "Dog eat bones..."

class Cat(Animal):
    def run(self):
        print "Cat is running..."
    def sleep(self):
        print "Cat is sleeping..."
```

#### 上述代码的讲解：
+ Animal 类实现了run函数。继承自object类，
+ Dog 和Cat 继承自 Animal类，并且Dog和Cat 都重写了基类的 run 函数。
+ Dog 和 Cat 还分别定义了自己的函数  eat 和 sleep


### 继承比较简单，跟C++很类似，下面开始进入多态，很显然，这里的run函数就是我们的 类似 C++中得虚函数。比如我们定义下面的函数：
```

def run_2(animal):
    animal.run()
    animal.run()

```

#### 其中 run_2函数的参数是animal类型的对象，那么下面的3中调用方式都是合法的。

```
run_2(Animal())
run_2(Dog())
run_2(Cat())
```
#### 这就是多态，与C++是一致的，可以将派生类的对象绑定到基类的类型，由于Python本身是动态语言，animal参数的类型也是运行时的类型（动态类型）。

### 怎样获取对象的信息
#### type 和 isinstance  在一般情况下是等价的。
#### 这里举几个简单的例子： 
```
type(123）  # int
type(“abc”)  # str

```
#### 但是，在继承关系中。
```
type(Dog()) == Animal  # False ,
```

#### 这里有悖常理，派生类的类型应该既可以是派生类本身，同时也是基类的类型。这里使用isinstance 可以解决这个问题。
```
isinstance(Dog(), Animal) #  True
isinstance(Dog(), Dog)  # True
isinstance(Dog() , (Dog, int)) # True , 只要属于后面括号内的任意一个类型，就为True
```

### 要想查看类的所有的属性，可以使用 dir 命令。 如： dir(Dog)

[参考资料](http://www.liaoxuefeng.com/wiki/001374738125095c955c1e6d8bb493182103fac9270762a000/0013868200385680e8cf932dba9433ea367de9aba2b4784000)
