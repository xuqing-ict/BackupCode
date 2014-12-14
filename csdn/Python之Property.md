
#### 在阅读[廖雪峰](http://www.liaoxuefeng.com/wiki/001374738125095c955c1e6d8bb493182103fac9270762a000/001386820062641f3bcc60a4b164f8d91df476445697b9e000)的Python的笔记时，读到了@property特性，发现略有不足，由于自己是初学，希望惠及更多的初学者吧。

### @property 的用途是什么呢？
#### 下面一步一步地介绍。

+ 定义类Student，拥有变量名name和score

```
class Student(object):
    def __init__(self,name,score):
        self.name = name
        self.score = score
```

#### 这样，我们可以在类外修改Student的实例的成员变量:

```
s1 = Student()
s1.name = "Lily"
s1.score = 9999 # 这里的定义是不合理的
```

#### 但是，**上述这样定义score是不会进行参数检查的，也就意味着我们不能执行必要的参数以及错误处理**。


#### 我们可以定义相应的set和get成员函数来访问成员变量score，并且进行参数检查。如下所示：

```
class Student(object):
    def __init__(self,name,score):
        self.name = name
        self.score = score
    def get_score(self): return self.score
    def set_score(self,score):
        if not isinstance(score, int):
            raise ValueError("invalid score!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self._score = score
```

#### 上述代码定义了score成员的set和get函数。（可能实际应用时，修改分数比较常见）

#### 现在，我们改变参数的代码是这样的：

```
s1 = Student()
s1.set_score(9999) #这里会抛出异常
```

#### 上述的第二种方式实现了set函数的参数检查，但是修改score的代码从简单的  s1.score = 90 变成了 s1.set_score(90) .我们怎么样才能做到既检验输入的参数又使得修改score的代码不变呢？

#### @Property便是这个作用。

#### 下面，我们讨论Python的高级特性 @Property。简单的说**@Properyty就是将成员函数的调用变成属性赋值**。

#### 于是有了下面的代码：

```
class Student(object):
    def __init__(self,name,score):
        self._name = name
        self._score = score
    @property
    def score(self): return self._score
    @score.setter
    def score(self,score):
        if not isinstance(score,int):
            raise ValueError("invalid score!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self._score = score
    @property
    def name(self): return self._name
s1 = Student("Lily", 90)
#s1.name = "Luly"
s1.score = 100
```

#### 关于上述代码的说明：
+ 可能你已经发现了，我的成员变量改成了_name 与 _score，这里首先是为了增加可读性，这两个变量是私有的。其次的原因见下面的误区分析。
+ 上述代码中的 s1.name = "Luly" 行会出现编译错误 * AttributeError: can't set attribute * ,也就是说这里不能直接这样改变，这是为什么呢？可以看到，在代码中，我并没有提供名称为name的set函数，
**这里值得注意的是，s1._name = "Lucy"  是可以运行通过的。但是我们之前说过了，假设用户足够自觉，不会去操作 _xxx 或者 __xxx这样的变量名**。
+ 按照上述代码的初衷，也就是说name是类的只读的属性。score是可修改的。
+ 关于@property 修饰的函数 score 就是个简单的get函数，该函数不需要任何参数（self不需要传入值），因此我们可以这样来调用这个函数 ,即 s1.score 即可。（这就是Property的用处，将函数调用转化为属性访问），相当于给score加了一层包裹。
+ 关于@score.setter 便是针对与 score函数包裹的成员变量的的set函数。当我们需要修改_score的值时，使用score函数，但是就像score是类的成员属性一样使用，例如上面的： s1.score = 100，实际上等价于 s1.score(100).

#### **注意，这里的函数名不一定要是score，可以是任何的字符串，这里只是为了方面说score函数是_score的包裹**，例如下面的代码：我们将score改成了AA，但是这样在:

```
class Student(object):
    def __init__(self,name,score):
        self._name = name
        self._score = score
    @property
    def AA(self): return self._score
    @AA.setter
    def AA(self,score):
        if not isinstance(score,int):
            raise ValueError("invalid score!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self._score = score
    @property
    def name(self): return self._name
s1 = Student("Lily", 90)
#s1.name = "Luly"
s1.AA = 100 # 这里相当于是 s1.AA(100)
```

### 好了，关于@Property的概念与用法就讲完了。本质上是定义了新的函数，该函数们执行set与get的功能，并且有@Property的包裹。并且将这些定义的函数当作属性一样来赋值。

#### 可能存在的陷阱：
#### 下面的代码是个大的陷阱，因为现在的函数已经不再是单纯的函数，而是可以直接用 = 来调用，例如上面的 score函数 的调用竟然是  s1.score = 100 .这样就会出现下面的问题：
```
class Student(object):
    def __init__(self,name,score):
        self.name = name
        self.score = score
    @property
    def score(self): return self.score
    @score.setter
    def score(self,score):
        if not isinstance(score,int):
            raise ValueError("invalid score!!!")
        if score < 0 or score > 100:
            raise ValueError("score must be between [0,100]!!!")
        self.score = score
    @property
    def name(self): return self.name

    def func(self):
        self.score = score

s1 = Student("Lily", 90)
s1.func()
```
### 上面的代码有两个很大的错误，
+ 你会发现，你无法定义Student的任何实例，为什么呢？ 首先@property把score和name两个成员函数可以当作成员变量来访问，那么在定义实例时，调用__init__函数的时候，self.name = name,这一句，Python会将左端的self.name当作函数调用，然而我们并未给name变量
定义set函数，于是错误信息为：AttributeError: can't set attribute.
+ 好的，我们接下来注释掉
```
@property
def name(self): return self.name
```
+ 这两行，那么接下来的运行还是错误的，为什么呢？是因为__init__函数代码的第二行 self.score = score, 很庆幸我们定义了score的set函数，
那么self.score调用score函数，当执行到score函数的最后一句self.score = score时， 我们回发现，式子的左端还是score函数调用，
如此往复，最终以函数递归深度达到上限退出程序。
#### 这里其实是一个很好的代码习惯，那就是尽量不要让函数名与变量名同名，便可以避免这些错误。

[参考资料](http://www.liaoxuefeng.com/wiki/001374738125095c955c1e6d8bb493182103fac9270762a000)
