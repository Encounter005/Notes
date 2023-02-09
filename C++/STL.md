# STL

<!--toc:start-->

- [STL](#stl)
  - [容器](#容器)
    - [vector](#vector)
    - [pair](#pair)
    - [string](#string)
    - [queue](#queue)
    - [priority_queue](#priorityqueue)
    - [dueue](#dueue)
    - [stack](#stack)
    - [set / multiset](#set-multiset)
    - [map / multimap](#map-multimap)
    - [unordered_set / unordered_map / unordered_multiset / unordered_multimap](#unorderedset-unorderedmap-unorderedmultiset-unorderedmultimap)
    - [bitset](#bitset)
  - [库函数](#库函数) - [lower_bound & upper_bound](#lowerbound-upperbound) - [sort](#sort) - [reverse](#reverse) - [nth_element](#nthelement)
  <!--toc:end-->

## 容器

### vector

> 倍增思想
> 支持比较运算（字典序）

```c++
    vector<int> a(10 , 3);
    a.size();//返回容器的大小
    a.empty();//判断容器是否为空
    a.clear();//清空整个容器
    a.front();//返回容器的第一个元素
    a.back();//返回容器末尾元素
    a.erase();//从下标开始删除到容器末尾
    a.push_back();//往容器末尾插入一个元素
    a.pop_back();//删除容器末尾元素
```

### pair

> 简单的二元组
> 支持比较运算（字典序）

```c++
pair<int ,  string> p;//类型可以任意
p = make_pair(12 , "shjefkl");
p.first//返回pair的第一个元素
p.second//返回pair的第二个元素
比较运算//先比较第一个关键字，如果第一个关键字一样则比较第二个关键字

```

### string

> 好用的字符串类

```c++
string a;
string a[10];//字符串数组，每个元素都是一个字符串
a.size();
a.empty();
a.clear();
a.back();
a.substr(%d , %d); //返回原串的子串，第一个参数是子串在原串的起始位置，第二个参数是子串的长度，忽略的话默认延长到原串的末尾
a.c_str();//返回string存储字符串的起始地址
a.find("char");//查找字符串，如果没有，会返回string::npos, 如果查到，返回第一次匹配成功的下标
```

### queue

> 队列 ， 先进先出

```c++
queue<int> a;
a.push();//向队尾插入一个元素
a.front();//返回队头
a.back();//返回队尾元素
a.pop();//弹出队头元素
没有clear()函数
a = queue<int>(); //清空原队列
```

### priority_queue

> 堆 , 默认是大根堆

```c++
priority_queue<int> a;
a.push();//插入一个元素
a.top();//返回堆顶元素
a.pop();//弹出堆顶元素
a.empty();
a.size();
没有clear()函数
a = priority_queue<int>(); //清空堆
定义成小根堆的方式 priority_queue<int , vector<int , greater<int>> a;
```

### dueue

> 双端队列

```c++
dueue<int> a;
a.size();
a.empty();
a.clear();
a.front();
a.back();
a.push_back();
a.pop_back();
a.push_front();//往容器首元素插入一个元素
a.pop_front();//弹出首元素
a.begin();
a.end();

```

### stack

> 栈

```c++
stack<int> a;
a.push();//向栈顶插入一个元素
a.top();//返回栈顶元素
a.pop();//弹出栈顶元素
a.empty();
a.size();
没有clear()函数
```

### set / multiset

> 基于平衡二叉树（红黑树）
> 不存在重复元素的集合
> multiset 允许重复元素存在

```c++

set<int> a;
a.insert();//插入一个元素
a.find();//查找一个元素，如果不存在返回a.end();
a.count(%d)//返回某一个数的个数
a.size();
a.empty();
a.clear();
a.erase(%d);//输入一个数x，删除所有x
            //输入一个迭代器，删除这个迭代器
a.lower_bound()/upper_bound() //
lower_bound(x)// 返回大于等于x的迭代器
upper_bound(x)// 返回大于x的迭代器
a.begin();
a.end();

```

### map / multimap

> 基于平衡二叉树（红黑树）

```c++
insert(); //插入的数是一个pair
erase();//输入的参数可以是pair或者迭代器
find();//
a.lower_bound()/upper_bound() //
lower_bound(x)// 返回大于等于x的迭代器
upper_bound(x)// 返回大于x的迭代器



```

### unordered_set / unordered_map / unordered_multiset / unordered_multimap

> 哈希表
> 不支持 lower_bound() , upper_bound()

### bitset

> 压位

## 库函数

### lower_bound & upper_bound

[A-B 数对](https://www.luogu.com.cn/problem/P1102)

> 处理二分问题，使用前一定要`先排序`
> lower_bound 的第三个参数传入一个元素 target，在两个迭代器（指针）指定的部分上执行二分查找，返回指向第一个大于等于 x 的元素的位置的迭代器（指针）。
> upper_bound 的用法和 lower_bound 大致相同，唯一的区别是查找第一个大于 target 的元素。当然，两个迭代器（指针）指定的部分应该是`提前排好序的`。

```c++
//用法
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n , target;

int main()
{
    cin >> n >> target;
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a , a + n);
    int i = lower_bound(a , a + n , target) - a;
    //查找小于等于target的元素
    int y = --(upper_bound(a , a + n , target) - a);

    return 0;
}
```

### sort

> 处理排序问题
> 底层逻辑：快排

[结构体排序](https://www.acwing.com/problem/content/864/ '三元组排序')

```c++
//用法
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;

int n , a[N];

bool cmp(st x)
{
    return x.t > x.y;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    //从小到大排序
    sort(a , a + n);

    //从大到小排序
    sort(a , a + n , greater<int>)

    //特定函数排序(用于结构体排序、堆排序等等)
    sort(a , a + n , cmp(x))
    //如果返回1为较大，返回0为较小
    return 0;
}
```

### reverse

> 反转一个容器(string , vector , array , set ....)

```c++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e5 + 10;
int a[N];
vector<int> A;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    reverse(a , a + n);
    reverse(A.begin() , A.end());
    return 0;
}
```

### nth_element

> 可以从某个序列中找到第 n 小的元素 K，并将 K 移动到序列中第 n 的位置处

> [求第 k 小的数](https://www.luogu.com.cn/problem/P1923)

```c++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e5 + 10;
int a[N];
vector<int> A;
int main()
{
    int k , n ;
    cin >> n >> k;
    for(int i = 0; i < n; i ++) cin >> a[i];

    nth_element(a , a + k - 1, a + n);
    nth_element(A.begin() , A.begin() + k - 1 , A.end());
    cout << a[k] << endl;

    return 0;
}

```
