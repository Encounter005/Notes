# Data-structure-and-Algorithm

<!-- vim-markdown-toc GFM -->

* [数据结构](#数据结构)
    * [链表](#链表)
    * [静态链表](#静态链表)
        * [单链表](#单链表)
        * [双链表](#双链表)
    * [栈](#栈)
        * [数组模拟](#数组模拟)
        * [单调栈](#单调栈)
    * [队列](#队列)
        * [数组模拟](#数组模拟-1)
        * [单调队列](#单调队列)
    * [Trie 树](#trie-树)
    * [并查集](#并查集)
    * [堆](#堆)
        * [小根堆](#小根堆)
        * [大根堆](#大根堆)
        * [堆的存储](#堆的存储)
        * [如何手写一个堆](#如何手写一个堆)
    * [哈希表](#哈希表)
        * [存储结构](#存储结构)
                * [1. 开放寻址法](#1-开放寻址法)
                * [2. 拉链法](#2-拉链法)
        * [字符串哈希方式](#字符串哈希方式)
* [算法](#算法)
    * [排序](#排序)
        * [快速排序](#快速排序)
        * [归并排序](#归并排序)
        * [堆排序](#堆排序)
    * [高精度运算](#高精度运算)
        * [高精度加法](#高精度加法)
        * [高精度减法](#高精度减法)
        * [高精度乘法](#高精度乘法)
        * [高精度除法](#高精度除法)
    * [KMP 算法](#kmp-算法)
    * [位运算](#位运算)
    * [离散化](#离散化)
    * [双指针](#双指针)
    * [二分](#二分)
        * [整数二分](#整数二分)
        * [浮点数二分](#浮点数二分)
    * [前缀和](#前缀和)
        * [一维](#一维)
        * [二维](#二维)
    * [差分](#差分)
        * [一维](#一维-1)
        * [二维](#二维-1)
    * [区间合并](#区间合并)
* [数学知识](#数学知识)
    * [斐波那契数列写法](#斐波那契数列写法)
    * [找质数](#找质数)
    * [找最大公约数](#找最大公约数)
    * [找最小公倍数](#找最小公倍数)
* [搜索与图论](#搜索与图论)
    * [DFS(深度优先搜索) && BFS(宽度优先搜索)](#dfs深度优先搜索--bfs宽度优先搜索)
        * [BFS](#bfs)
        * [DFS](#dfs)
    * [树与图(有向图)](#树与图有向图)
        * [存储](#存储)
            * [邻接表](#邻接表)
        * [深度优先遍历](#深度优先遍历)
        * [宽度优先遍历](#宽度优先遍历)
    * [拓补排序](#拓补排序)
    * [最短路径问题](#最短路径问题)
        * [Dijkstra](#dijkstra)
            * [朴素版 Dijkstra](#朴素版-dijkstra)
            * [堆优化版 Dijkstra](#堆优化版-dijkstra)
        * [Bellman-Ford](#bellman-ford)
            * [一些问题](#一些问题)
        * [Spfa](#spfa)
        * [总结](#总结)
* [动态规划](#动态规划)
    * [背包问题](#背包问题)
        * [01 背包](#01-背包)
            * [关于一维优化](#关于一维优化)
            * [为什么能转化成一维](#为什么能转化成一维)
                * [如何转化成一维](#如何转化成一维)
        * [完全背包](#完全背包)
            * [优化问题](#优化问题)
        * [多重背包问题](#多重背包问题)
        * [分组背包问题](#分组背包问题)
    * [线性 DP](#线性-dp)

<!-- vim-markdown-toc -->

# 数据结构

## 链表

![微信图片_20230101222021.png](https://img1.imgtp.com/2023/02/18/Hf9jMWkb.png)
![edrtfyghujk.png](https://img1.imgtp.com/2023/02/18/0UNbeGFA.png)

> 初始化

```c++
#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x) , next(nullptr) {}

};
```

> 遍历链表 + 添加头节点 + 删除一个节点

```c++

#include<iostream>
using namespace std;


struct Node
{
    int val;
    Node *next;
    Node(int _val) : val(_val) , next(nullptr){}
} *head;

int main()
{
  Node *p = new Node(1);
  auto *q = new Node(2);
  p->next = q;
  auto *o = new Node(3);
  q->next = o;

  Node *head = p;
  for(Node *i = head; i ; i = i->next) cout << i->val << endl;

  return 0;
}
```

> 生成链表

```c++
class LinkedList{

    public:

    //生成链表
    ListNode* createLinkedList(int arr[], int n){

        if ( n == 0){
            return NULL;
        }

        ListNode *head = new ListNode(arr[0]);
        ListNode *curNode = head;

        for (int i = 1; i < n; ++i) {
            curNode->next = new ListNode(arr[i]);
            curNode = curNode->next;
        }
        return head;
    }

```

> 反转链表

```c++
ListNode *reverseLinked(ListNode *head)
{
 ListNode *preNode = NULL;
 ListNode *curNode = head;

 while(curNode != NULL)
 {
  ListNode *nextNode = curNode->next;
  curNode->next = preNode;
  preNode = curNode;
  curNode = nextNode;
 }
 //preNode变成头节点
 return preNode;
}
```

> 移除值为 val 的所有节点

```c++
 ListNode* removeElements(ListNode *head, int val){

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *cur = dummyHead;
        while (cur->next != NULL){
            if (cur->next->val == val){
                ListNode *delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            } else{
                cur = cur->next;
            }
        }

        ListNode *returnNode = dummyHead->next;
        delete dummyHead;

        return returnNode;
    }
```

> 合并两个有序的链表

```c++
 ListNode *mergeTwoLists(ListNode *headA, ListNode *headB){

        if (headA == NULL){
            return headB;
        } else if (headB == NULL){
            return headA;
        }

        ListNode *mergedHead = NULL;

        if (headA->val < headB->val){

            mergedHead = headA;
            mergedHead->next = mergeTwoLists(mergedHead->next,headB);

        } else {

            mergedHead = headB;
            mergedHead->next = mergeTwoLists(headA,mergedHead->next);

        }
        return mergedHead;
    }
```

> 找到两个链表的交点
> [两个链表的第一个公共节点](200~<https://www.acwing.com/problem/content/62/)>

```c++
ListNode *findIntersectionNode(ListNode *headA, ListNode*headB){

        int lengthA = calculateLength(headA);
        int lengthB = calculateLength(headB);

        ListNode *pA = headA;
        ListNode *pB = headB;

        int n = lengthA - lengthB;

        for (int i = 0; i < abs(n); ++i) {

            if(n > 0){

                pA = pA->next;

            } else{

                pB = pB->next;
            }
        }

        while (pA && pB){

            //found first same value node
//            if (pA->val == pB->val){
//                return pB;
//            }

            //found first same address node(intersection node)
            if (pA->val == pB->val){
                return pB;
            }

            //move node
            pA = pA->next;
            pB = pB->next;
        }

        return NULL;
    }
```

## 静态链表

### 单链表

[单链表](https://www.acwing.com/problem/content/828/)

```c++
#include<iostream>
using namespace std;

const int N = 1e6 + 10;



//head表示头节点的下标
//e[i]表示节点i的值
//ne[i]表示节点i的next指针是多少
//idx表示当前已经用到了哪个点
int head , e[N] , ne[N] , idx;

void init()
{
    head = -1;
    idx = 0;
}

//将x插到头节点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

//将x插入到下标是k的点后面
void add(int k , int x)
{

    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}


//将下标是k的后面的点删掉
void Remove(int k)
{
    ne[k] = ne[ne[k]];
}



```

### 双链表

[双链表](https://www.acwing.com/problem/content/829/)

```c++
#include<iostream>
using namespace std;
const int N = 1e5 + 10;

//r[N]表示当前这个点右边的点是谁
//l[N]表示当前这个点左边的点是谁
//e[N]表示当前这个点的值
//idx表示已经用到了哪个点

int e[N] , l[N] , r[N] , idx;



void init()
{
    //0表示左端点，1表示右端点
    r[0] = 1 , l[1] = 0;
    idx = 2;
}

//在下标是k的点的右边插入x
void add(int k , int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}

//删除第k个点
void Remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

```

## 栈

### 数组模拟

```c++
// tt表示栈顶
int stk[N], tt = 0;

// 向栈顶插入一个数
stk[ ++ tt] = x;

// 从栈顶弹出一个数
tt -- ;

// 栈顶的值
stk[tt];

// 判断栈是否为空
if (tt > 0)
{

}

```

### 单调栈

[单调栈](https://www.acwing.com/problem/content/832/)

![1616738kj1l431.jpg](https://img1.imgtp.com/2023/02/18/jgudFwiz.jpg)

> 常见模型：找出每个数左边离它最近的比它大/小的数

```c++
int tt = 0;
for (int i = 1; i <= n; i ++ )
  while (tt && check(stk[tt], i)) tt -- ;

stk[ ++ tt] = i;
}

```

## 队列

### 数组模拟

> 1. 普通队列

```c++
// hh 表示队头，tt表示队尾
int q[N], hh = 0, tt = -1;

// 向队尾插入一个数
q[ ++ tt] = x;

// 从队头弹出一个数
hh ++ ;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh <= tt)
{

}
```

> 2. 循环队列

```c ++
// hh 表示队头，tt表示队尾的后一个位置
int q[N], hh = 0, tt = 0;

// 向队尾插入一个数
q[tt ++ ] = x;
if (tt == N) tt = 0;

// 从队头弹出一个数
hh ++ ;
if (hh == N) hh = 0;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh != tt)
{

}

```

### 单调队列

[单调队列](https://www.acwing.com/problem/content/156/)

![1616738kjl431.jpg](https://img1.imgtp.com/2023/02/18/IlTEwaLG.jpg)

> 常见模型：找出滑动窗口中的最大值/最小值

```c++
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // 判断队头是否滑出窗口
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}

```

## Trie 树

![Screenshot_20230101_174144.png](https://img1.imgtp.com/2023/02/18/wJxs07ix.png)

[Trie 字符串统计](https://www.acwing.com/problem/content/837/)
[Trie 存储整数](https://www.acwing.com/problem/content/145/)

> 高效的存储和查找字符串集合的数据结构

```c++
#include<iostream>
using namespace std;
const int N = 1e5 + 10;

// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

char str[N];
int son[N][26] , cnt[N] , idx;//下标是0的点，既是根节点，又是空节点

int n;

//插入一个字符串
void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }

    cnt[p] ++;
}


//查询字符串出现次数
int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }

    return cnt[p];
}
```

## 并查集

![Screenshot_20230101_174216.png](https://img1.imgtp.com/2023/02/18/5Kr3MoWp.png)

[合并集合](https://www.acwing.com/problem/content/838/)

[连通块中点的数量](https://www.acwing.com/problem/content/839/)

> 将两个集合合并
> 询问两个元素是否在一个集合当中

```markdown
每一个集合用一棵树来表示
树根的编号就是整个集合的编号
每个节点存储它的父节点
p[x]表示 x 的父节点
```

> Q1： 如何判断树根： if(p[x] == x)
> Q2：如何求 x 的集合编号：while(p[x] != x) x = p[x]
> Q3：如何合并两个集合： p[x]是 x 的集合编号，p[y]是 y 的集合编号 p[x] = y;
> 优化：路径压缩

```C++
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];

int find(int x) //返回x的祖宗节点 + 路径压缩
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d" , &n , &m);
    for(int i = 1; i <= n; i ++) p[i] = i;

    while(m --)
    {
        char op[2];
        int a , b;
        scanf("%s%d%d" , op , &a , &b);
        if(op[0] == 'M') p[find(a)] = find(b);
        else
        {
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
```

## 堆

> 完全二叉树

### 小根堆

![20190412193512956.png](https://img1.imgtp.com/2023/02/18/5TAILlqa.png)

### 大根堆

![20190412193413102.png](https://img1.imgtp.com/2023/02/18/BLbwtwTA.png)

### 堆的存储

![Screenshot_20221229_203502.png](https://img1.imgtp.com/2023/02/18/rlFxwPCq.png)

### 如何手写一个堆

1. 插入一个数 `heap[++ size] = x; up(size);`
2. 求集合当中的最小值 `heap[1]`
3. 删除最小值 `heap[1] = heap[size]; size --; down(1);`
4. 删除任意一个元素 `heap[k] = heap[size]; size --; down(k); up(k);`
5. 修改任意一个元素 `heap[k] = x; down(k); up(k);`

[模拟堆](https://www.acwing.com/problem/content/841/)

```c++
down(int x)
{
  int t = x; //用于存储最小节点的下标
  if(x * 2 <= size && x * 2 <  h[t]) t = x * 2;
  if(x * 2 + 1 <= size && x * 2 + 1 < h[t]) t = x * 2 + 1;
  if(u != t)
  {
    swap(h[u] , h[t]);
    down(t);
  }
}

up(int x)
{
  while(x / 2 && h[x / 2] > h[x])
  {
    swap(h[x / 2] , h[x]);
    x /= 2;
  }
}

```

## 哈希表

> 0~1e9 $\Rightarrow$ 0~1e5

### 存储结构

[模拟散列表](https://www.acwing.com/problem/content/842/)
[字符串哈希](https://www.acwing.com/problem/content/843/)

##### 1. 开放寻址法

![Screenshot_20221230_222421.png](https://img1.imgtp.com/2023/02/18/AmhLaxkw.png)

1. 找大于最大值的一个质数
2. 插入 && 查找操作
   > 先求哈希值 `int k = (x % N + N) % N;`
   > 将哈希值插入 h[k]，如果这个点上有存，就换下一个，如果到末尾都有值，就从下标 0 的位置开始找

```c++
#include<iostream>
#include<cstring>
using namespace std;
const int N = 200003 , null = 0x3f3f3f3f;

int h[N];

int n;

int find(int x)
{
    int k = (x % N + N) % N;
    while(h[k] != null && h[k] != x)
    {
        k ++;
        if(k == N) k = 0;
    }
    return k;
}

int main()
{
//    for(int i = 200000 ;; i ++)
//    {
//        bool falg = true;
//        for(int j = 2; j * j <= i; j ++)
//        {
//            if(i % j == 0)
//           {
//                flag = false;
//                break;
//            }
//            if(flag)
//            {
//                cout << i << endl;
//                break;
//            }
//       }
//    }

    memset(h , null , sizeof(h));
    cin >> n;
    while(n --)
    {
        int k , x;
        string op;
        cin >> op >> x;
        k = find(x);
        if(op == "I") h[k] = x;
        else
        {
            if(h[k] != null) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}

```

##### 2. 拉链法

![Screenshot_20221230_211314.png](https://img1.imgtp.com/2023/02/18/F0oiyKb9.png)

1. 找大于最大值的一个质数
2. 插入操作
   > 先求哈希值 `int k = (x % N + N) % N;`
   > 如果有两个数的哈希值一样(哈希冲突)，用单链表的方式存储
3. 查找操作

   > 遍历整个哈希表

```c++
//h[N] 为哈希表
//e[N] 存入的值
//ne[N] next指针
//idx 表示当前用到了哪个点

for(int i = N; ; i ++)
{
    bool flag = true;
    for(int j = 2; j * j <= i; j ++)
    {
        if(i % j == 0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout << i;
        break;
    }

}

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i])
    {
        if(e[i] == x) return true;
    }
    return false;
}
```

### 字符串哈希方式

> 比 kmp 好使
> 记录不能从 0 开始
> ![Screenshot_20230106_195755.png](https://img1.imgtp.com/2023/02/18/a3X3ObmV.png)

```c++
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
typedef unsigned long long ULL;
int n , m , P = 131;
char str[N];

ULL h[N] , p[N];

ULL get(int l , int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    scanf("%d%d%s" , &n , &m , str + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P+ str[i];//预处理前缀和
    }

    while(m --)
    {
        int l1 , r1 , l2 , r2;
        scanf("%d%d%d%d" , &l1 , &r1 , &l2 , &r2);
        if(get(l1 , r1) == get(l2 , r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}


```

# 算法

## 排序

### 快速排序

> 用两个指针不断递归交换

[快排](https://www.acwing.com/problem/content/787/)

```c++
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int n;

void quick_sort(int a[] , int l , int r)
{
  if(l >= r) return ;
  int i = l - 1 , j = r + 1;
  int mid = a[l + r >> 1];
  while(i < j)
  {
    do i ++; while(a[i] < mid);
    do j --; while(a[j] > mid);
    if(i < j) swap(a[i] , a[j]);
  }
  quick_sort(a , l , j) , quick_sort(a , j + 1 , r);

}

int main()
{
  scanf("%d" , &n);
  for(int i = 0; i < n; i ++) scanf("%d" , &a[i]);
  quick_sort(a , 0 , n - 1);
  for(int i = 0; i < n; i ++) printf("%d " , a[i]);

  return 0;
}

```

### 归并排序

> 分治思想

[逆序对的数量](https://www.acwing.com/problem/content/790/)

```c++
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N], tmp[N];
void merge_sort(int q[], int l, int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(q, l , mid), merge_sort(q , mid + 1 , r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(q[i] < q[j]) tmp[k ++] = q[i ++];
        else tmp[k ++] = q[j ++];
    }
    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];
    for(int i = l, j = 0; i <=r ; i ++, j ++) q[i] = tmp[j];
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q , 0 , n - 1);
    for(int i = 0; i < n; i ++) printf("%d ", q[i]);
    return 0;
}

```

### 堆排序

[堆排序](https://www.acwing.com/problem/content/840/)

> 将一堆数构建成小根堆或者大根堆
> 每次求得最小值或者最大值后删除根节点

```c++
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int h[N] , Size;
int n , m;

void down(int x)
{
  int t = x; // 用于存储最小节点的下标
  if(x * 2 <= Size && h[x * 2] < h[t]) t = x * 2;
  if(x * 2 + 1 <= Size && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
  if(x != t)
  {
    swap(h[t] , h[x]);
    down(t);
  }

}

int main()
{
  scanf("%d%d" , &n , &m);
  for(int i = 1; i <= n; i ++) scanf("%d" , &h[i]);
  Size = n;

  for(int i = n / 2; i; i --) down(i);

  while(m --)
  {
    printf("%d " , h[1]);
    //删除操作
    h[1] = h[Size];
    Size --;
    down(1);
  }

  return 0;
}
```

## 高精度运算

> 模拟人类四则运算的过程

### 高精度加法

[高精度加法](https://www.acwing.com/problem/content/793/)

```c++
#include<iostream>
#include<vector>
using namespace std;
string a, b;
vector<int> A , B;

vector<int> add(vector<int> &A , vector<int> &B)
{
    if(A.size() < B.size()) return add(B , A);

    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i ++)
    {
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(t);
    return C;
}


int main()
{
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    auto C =  add(A , B);
    for(int i = C.size() - 1; i >= 0; i --) cout << C[i];

    return 0;
}


```

### 高精度减法

[高精度减法](https://www.acwing.com/problem/content/794/)

```c++
#include<iostream>
#include<vector>
using namespace std;
string a, b;
vector<int> A , B;

bool cmp(vector<int> &A , vector<int> &B)
{
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i --)
    {
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}


vector<int> sub(vector<int> &A , vector<int> &B)
{
    int t = 0;
    vector<int> C;
    for(int i = 0; i < A.size(); i ++)
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if(t >= 0) t = 0;
        else t = 1;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}




int main()
{
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    if(cmp(A , B))
    {
        auto C = sub(A , B);
        for(int i = C.size() - 1; i >= 0; i --) cout << C[i];
    }
    else
    {
        cout << "-";
        auto C = sub(B, A);
        for(int i = C.size() - 1; i >= 0; i --) cout << C[i];
    }

    return 0;
}


```

### 高精度乘法

[高精度乘法](https://www.acwing.com/problem/content/795/)

```c++
#include<iostream>
#include<vector>
using namespace std;
string a;
int b;
vector<int> A;

vector<int> mul(vector<int> &A , int b)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size() || t; i ++)
    {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}


int main()
{
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    auto C = mul(A , b);

    for(int i = C.size() - 1; i >= 0; i --) cout << C[i];

    return 0;
}

```

### 高精度除法

[高精度除法](https://www.acwing.com/problem/content/796/)

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int b , r;
string a;
vector<int> A;

vector<int> div(vector<int> &A , int b , int &r)
{
   vector<int> C;
   for(int i = A.size() - 1; i >= 0; i --)
   {
       r = A[i] + r * 10;
       C.push_back(r / b);
       r %= b;
   }
   reverse(C.begin() , C.end());
   while(C.size() > 1 && C.back() == 0) C.pop_back();
   return C;
}



int main()
{
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

    auto C = div(A , b , r);
    for(int i = C.size() - 1; i >= 0; i --) cout << C[i];
    cout << endl << r;

    return 0;
}

```

## KMP 算法

> next[]数组 -- 找到最长的模式串相等的前缀和后缀
> 快速匹配两个字符串

[kmp 算法](https://www.acwing.com/problem/content/833/)

```c++
#include<iostream>
usin namespace std;
const int N = 1e5 + 10 , M = 1e6 + 10;
int n , m;
char p[N]  , s[M];
int ne[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;


    //求next数组的过程
    for(int i = 2 , j = 0; i <= n; i ++)
    //i != 1的原因，next[0] = 0 , 如果第一个字符不匹配，就从0开始
    {
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j ++;
        ne[i] = j;//归零
    }


    //KMP匹配过程
    for(int i = 1 , j = 0; i <= m; i ++)
    {
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j ++;

        //匹配成功
        if(j == n)
        {
            printf("%d " , i - n);//下标从0开始
            j = ne[j];
        }
    }

    return 0;
}
```

## 位运算

![微信图片_20230101222016.jpg](https://img1.imgtp.com/2023/02/18/73U1u52i.jpg)
[位运算](https://www.acwing.com/problem/content/803/)

```c++
求n的第k位数字: n >> k & 1
返回n的最后一位1：lowbit(n) = n & -n
```

```c++
#include<iostream>
using namespace std;
int n ;
const int N = 1e5 + 10;
int a[N];

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    scanf("%d" , &n);
    for(int i = 0; i < n; i ++)
    {
        int cnt = 0;
        scanf("%d" , &a[i]);
        while(a[i]) a[i] -= lowbit(a[i]) ,  cnt ++;
        printf("%d " , cnt);
    }

    return 0;
}

```

## 离散化

> 遇到数轴，并在数轴上进行操作可以用

![321769773.jpg](https://img1.imgtp.com/2023/02/18/6RA4jHZF.jpg)

```c++
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}

```

## 双指针

> 一种对暴力的优化，需要找到一种性质

## 二分

> 可用在容器中找到符合条件的数

### 整数二分

![Screenshot_20230215_104956.png](https://img1.imgtp.com/2023/02/15/Qdhxm6Ir.png)

```c++
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}


```

### 浮点数二分

```c++
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求(比题目要求多两位)
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```

## 前缀和

> 新建一个数组用于存储原数组的前 n 项和
> ![nwXML.png](https://c2.im5i.com/2023/02/02/nwXML.png)

### 一维

```c++

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int N = 1e5 + 10;
int a[N], s[N];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];

  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", s[r] - s[l - 1]);
  }

  return 0;
}
```

### 二维

## 差分

> 经常用于维护一个特定的区间
> ![20201217174809672.png](https://img1.imgtp.com/2023/02/18/3nThneQf.png) > ![20201213222213524.png](https://img1.imgtp.com/2023/02/18/9fQAgQiU.png)

### 一维

```c++
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int n, m;

void insert(int l, int r, int c) {
  b[l] += c;
  b[r + 1] -= c;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    insert(i, i, a[i]);
  }

  while (m--) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    insert(l, r, c);
  }

  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + b[i];
    cout << a[i] << ' ';
  }
  return 0;
}

```

### 二维

![20201214201734653.png](https://img1.imgtp.com/2023/02/18/umJspYCq.png)
![20201216215336857.png](https://img1.imgtp.com/2023/02/18/JoBcD4z9.png)

## 区间合并

![321hbjkm9773.jpg](https://img1.imgtp.com/2023/02/18/5ZmJlCxk.jpg)

```c++
// 将所有存在交集的区间合并
void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}
```

# 数学知识

## 斐波那契数列写法

> 循环

```c++
int search()
{
    int n , a = 0 , b = 1 , c = 0;
    cin >> n;
    while(n -- ){
        cout << a << ' ';
        c = a + b;
        a = b, b = c;
    }

    return 0;
}
```

> 递归

```
int func(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(n > 2) return func(n - 1) + func(n - 2);
}

```

## 找质数

```c++
void search()
{
    for(int i = 100010; i ; i --)
    {
        bool flag = true;
        for(int j = 2; j * j <= i; j ++)
        {
            if(i % j == 0)
            {
                flag = false;
                break;
            }
            if(flag) cout << i << end;
        }
    }
    return 0;
}

```

## 找最大公约数

```c++
int lcm(int a , int b)
{
    for(int i = 10000 ;; i --)
    {
        if(i % a == 0 && i % b == 0)
        {
            return i;
        }
    }
    return 0;
}


```

## 找最小公倍数

```c++
int gcd(int a , int b)
{
    for(int i = 1; i <= a * b; i ++)
    {
        if(i % a == 0 && i % b == 0) return i;
    }
    return 0;
}

```

# 搜索与图论

## DFS(深度优先搜索) && BFS(宽度优先搜索)

### BFS

> BFS
> ![Screenshot_20230108_204554.png](https://img1.imgtp.com/2023/02/18/Hj4X8U0p.png)

[走迷宫](https://www.acwing.com/problem/content/846/)

```c++
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 110;
int p[N][N], d[N][N], n, m;
typedef pair<int, int> PII;

//p[N][N]存放地图
//d[N][N]存储每一个点到起点的距离



queue<PII> q;

int bfs() {
  q.push({0, 0});

  int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};//初始化四个方向的向量
  memset(d, -1, sizeof(d)); //距离初始化，-1表示这个点没走过
  d[0][0] = 0;// 标记起点
  while (q.size()) {
    PII t = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];//求下个走的点的坐标
      if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && p[x][y] == 0) {//判断是否越界以及是否走过
        d[x][y] = d[t.first][t.second] + 1;//储存到起点的距离
        q.push({x, y});//将新的坐标入队
      }
    }
  }
  return d[n - 1][m - 1];//返回终点到起点的距离
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> p[i][j];

  cout << bfs() << endl;
  return 0;
}



```

---

### DFS

> DFS
> ![Screenshot_20230109_113350.png](https://img1.imgtp.com/2023/02/18/OSBqCfLG.png)

[排列数字](https://www.acwing.com/problem/content/844/)
[n 皇后问题](https://www.acwing.com/problem/content/845/)

```c++
const int N = 10;
int n;
int path[N];
bool st[N];

void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0; i < n; i ++) cout << path[i] << ' ';
        cout << endl;
    }

    for(int i = 1; i <= n; i ++)
    {
        if(!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;//恢复现场
        }
    }


}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);

    cin >> n;
    dfs(0);

    return 0;
}
```

---

## 树与图(有向图)

> 树是一种特殊的图

![Screenshot_20230120_173932.png](https://img1.imgtp.com/2023/02/18/Y0e3Y8sb.png)

### 存储

[树的重心](https://www.acwing.com/problem/content/848/)

#### 邻接表

```c++
int h[N] , e[N] , ne[N] , idx;

// h[N]表示第几个链表，e[N]用来存储节点的值，ne[N]表示next的指针，idx存储当前用到了哪个点

#include<cstring>
void init()
{
  memset(h , -1 , sizeof(h));
}

void add(int a , int b)
{
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx ++;
}

// 无向图
add(a , b) , add(b , a);
```

---

### 深度优先遍历

![Screenshot_20230120_175205.png](https://img1.imgtp.com/2023/02/18/SmLox7Uq.png)
![Screenshot_20230120_175256.png](https://img1.imgtp.com/2023/02/18/E70ECaDL.png)

[树的重心](https://www.acwing.com/problem/content/848/)

```c++
void dfs(int u)
{
  st[u] = true;// 标记一下，表示这个点已经被搜过了
  for(int i = h[u]; i != -1; i = ne[i])
    {
      int j = e[i];
      if(!st[j]) dfs(j);
    }
}

```

### 宽度优先遍历

> 队列维护

![Screenshot_20230217_103432_com.huawei.browser.jpg](https://img1.imgtp.com/2023/02/17/vTe7vnRf.jpg)

[图中点的层次](https://www.acwing.com/problem/content/description/849/)

```c++
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int d[N], q[N];
int n, m;
void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}

int bfs() {
  int hh = 0, tt = -1;
  q[0] = 1;
  memset(d, -1, sizeof(d));

  d[1] = 0;
  while (hh <= tt) {
    int t = q[hh++];

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (d[j] == -1) {
        d[j] = d[t] + 1;
        q[++tt] = j;
      }
    }
  }

  return d[n];
}
int main() {

  cin >> n >> m;
  memset(h, -1, sizeof(h));

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }

  cout << bfs() << endl;
  return 0;
}

```

## 拓补排序

> 图的 bfs 的应用，针对有向图

![Screenshot_20230217_113622_com.newskyer.draw.jpg](https://img1.imgtp.com/2023/02/17/Nw4h8fR6.jpg)
[有向图的拓补排序](https://www.acwing.com/problem/content/850/)

```c++
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n, m;
int q[N], d[N];        // d[]表示每个点的出度
void add(int a, int b) // 建图
{
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}
bool topsort() {
  int hh = 0, tt = -1; // 初始化队列
  for (int i = 1; i <= n; i++)
    if (!d[i])
      q[++tt] = i; // 将入度为0的节点入队
  // 一个有向无环图一定至少存在一个入度为0的点
  while (hh <= tt) {
    int t = q[hh++];                         // 将起点入队
    for (int i = h[t]; i != -1; i = ne[i]) { // 枚举出边
      int j = e[i];
      d[j]--; // 删掉t->j的出边
      if (d[j] == 0)
        q[++tt] = j; // 如果这个节点的入度为0，入队
    }
  }
  return tt == n - 1; // 如果所有的点都完成排序且不带环，返回true
}
int main() {
  cin >> n >> m;
  memset(h, -1, sizeof(h));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    d[b]++;
  }
  if (topsort()) {
    for (int i = 0; i < n; i++)
      cout
          << q[i]
          << ' '; // 由于所有的节点都入过队，值都存在队列里面，所以直接遍历队列就可以输出
  } else
    puts("-1");
  return 0;
}

```

## 最短路径问题

![Screenshot_20230312_104917_com.acwing.app.acwing_app.jpg](https://img1.imgtp.com/2023/03/12/4g2az1HI.jpg)

### Dijkstra

#### 朴素版 Dijkstra

> 一定不可以有负权边

[朴素 Dijkstra 求最短路径](https://www.acwing.com/problem/content/851/)

![Screenshot_20230312_112015.png](https://img1.imgtp.com/2023/03/12/4EC70TJK.png)

```c++
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 510;

int g[N][N]; // 稠密图用邻接矩阵来存
int dist[N]; // 存储从1号点到每个点的最短距离
bool st[N];  // 储存当前点的最短距离是否确定
int n, m;

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;

  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!st[j] && (t == -1 || dist[t] > dist[j])) // 寻找还未确定最短路的点中路径最短的点
        t = j;
    st[t] = true;

    for (int j = 1; j <= n; j++) // 依次更新每个点所到相邻的点路径值
      dist[j] = min(dist[j], dist[t] + g[t][j]);
  }
  if (dist[n] == 0x3f3f3f3f)
    return -1;
  return dist[n];
}

int main() {

  scanf("%d%d", &n, &m);

  memset(g, 0x3f, sizeof g); // 初始化邻接矩阵

  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a][b] = min(g[a][b], c); // 由于存在重边和自环，要存储最短的距离
  }

  auto ans = dijkstra();
  printf("%d", ans);

  return 0;
}

```

#### 堆优化版 Dijkstra

> 通过堆可以在一堆数找出最大值/最小值的特点来优化寻找点与点之间最小距离的过程

[堆优化 Dijkstra](https://www.acwing.com/problem/content/852/)
![Screenshot_20230312_130609.png](https://img1.imgtp.com/2023/03/12/SRh0YyGD.png)

```c++
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using PII = pair<int, int>;

const int N = 1e6 + 10;
int h[N], ne[N], e[N], idx, dist[N],
    w[N]; // w[]存的是权重，也就是每个点的距离 ，
          // dist[]存的是每个点之间的最小距离
int n, m;
bool st[N];
void add(int a, int b, int c) {
  // 如果出现重边也没有关系，假设1->2有权重为2和3的边，再遍历到点1的时候2号点
  // 的距离会更新两次放入堆中
  // 这样堆中就会有冗余的点，但是在弹出的时候还是会弹出最小值(2 + x)
  // (x为之前确定的最短路径) 并在st[]中记录一下，下一次弹出时会continue不会执行
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx++;
}

int Dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> heap; // 定义小根堆

  // 为什么heap里面存的是pair
  // 首先小根堆需要根据距离来排序。
  // 其次在从堆中拿出来的时候要知道这个点是哪个点，否则无法更新邻接点，所以第二个变量要存点
  heap.push({0, 1});
  // 由于pair排序会先根据first，如果first相等，再根据second
  // 所以要根据距离来排序
  while (heap.size()) {
    auto t = heap.top(); // 取不在集合S中距离最短的点
    heap.pop();
    int ver = t.second, distance = t.first;
    if (st[ver])
      continue;

    st[ver] = true;

    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > distance + w[i]) {
        dist[j] = distance + w[i];
        heap.push({dist[j], j}); // i 只是个下标，e中存储的是i这个下标对应的点
      }
    }
  }
  if (dist[n] == 0x3f3f3f3f)
    return -1;
  return dist[n];
}

int main() {

  cin >> n >> m;
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }

  int ans = Dijkstra();
  cout << ans << endl;

  return 0;
}

```

### Bellman-Ford

> 出现负权边，可以判断负环，但是时间复杂度高

[有边数限制的最短路](https://www.acwing.com/problem/content/855/)

![652_fa97a4d6a4-1.png](https://img1.imgtp.com/2023/03/14/biIGtVXj.png)

```c++
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 510, M = 1e5 + 10;

struct Edge {
  int a, b, w;
} e[M];

int n, m, k;            // k代表最短路径最多包含k条边
int dist[N], backup[N]; // 备份数组，防止串联
void bellman_ford() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;

  for (int i = 0; i < k; i++) { // k次循环
    memcpy(backup, dist, sizeof dist);

    for (int j = 0; j < m; j++) {
      int a = e[j].a, b = e[j].b, w = e[j].w;
      dist[b] = min(dist[b], backup[a] + w);
      // 使用backup:
      // 避免给a更新后立马更新b，这样b一次性最短路径就多了两条边出来了
    }
  }
}

int main() {

  scanf("%d%d%d", &n, &m, &k);

  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    e[i] = {a, b, w};
  }

  bellman_ford();

  if (dist[n] > 0x3f3f3f3f / 2)
    puts("impossible");
  else
    printf("%d", dist[n]);
  return 0;
}

```

#### 一些问题

1. 为什么需要 backup[]数组

- 为了避免如下的串联情况，在变数限制为一条的情况下，节点`3`的距离应该是 3，但是由于串联情况，利用`本轮跟心的节点2`更新了节点`3`的距离，所以现在及诶点`3`的距离是 2
  ![652_8fb5d1dca4-2.png](https://img1.imgtp.com/2023/03/14/Tr9K5t5P.png)

- 正确的做法是`用上轮节点2更新的距离-- 无穷大`，来更新节点`3`,再取最小值，所以节点`3`离起点的距离是 3
  ![652_8fb5d1dca4-2.png](https://img1.imgtp.com/2023/03/14/Tr9K5t5P.png)

2. 为什么是`dist[n] > 0x3f3f3f3f / 2`, 而不是`dist[n] > 0x3f3f3f3f`

- `5`号节点距离起点的距离是无穷大，利用`5`号节点更新 n 号节点距离起点的距离，将得到$10^9 - 2$, 虽然小于$10^9$，但是并不存在最短路(在边数限制在 k 条的条件下)

![652_1aa3df28a4-4.png](https://img1.imgtp.com/2023/03/14/31dsqYAD.png)

### Spfa

> 对 Bellman-ford 算法的优化

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int , int>;

const int N = 1e5 + 10;
int n , m;
int dist[N] , h[N] , e[N] , ne[N] , w[N] , idx;
bool st[N];

void add(int a , int b , int c) {

  e[idx] = b;
  ne[idx] = h[a];
  w[idx] = c;
  h[a] = idx ++;
}

void spfa() {
  memset(dist , 0x3f , sizeof dist);
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  st[1] = 1;

  while(q.size()) {
    auto t = q.front();
    q.pop();
    st[t] = 0;

    for(int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if(dist[j] > dist[t] + w[i]) {
        dist[j] = dist[t] + w[i];
        if(!st[j]) {
          q.push(j);
          st[j] = 1;
        }
      }
    }

  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(h , -1 , sizeof h);
  cin >> n >> m;

  while(m --) {

    int a , b, c;
    cin >> a >> b >> c;
    add(a , b , c);
  }
  spfa();
  if(dist[n] == 0x3f3f3f3f) puts("impossible");
  else cout << dist[n] << endl;

  return 0;
}


```

使用 Spfa()判断负权

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int , int>;
const int N = 1e5 + 10;
int dist[N] , cnt[N] , e[N] , ne[N] , w[N] , idx , h[N];
int n , m;
bool st[N];
void add(int a , int b  , int c) {
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx ++;
}

bool spfa() {
  queue<int> q;
  for(int i = 1; i <= n; i ++) {
    q.push(i);
    st[i] = true;
  }

  while(q.size()) {
    auto t = q.front();
    q.pop();

    st[t] = false;

    for(int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if(dist[j] > dist[t] + w[i]) {
        dist[j] = dist[t] + w[i];
        cnt[j] = cnt[t] + 1;

        if(cnt[j] >= n) return true;
        if(!st[j]) {
          st[j] = true;
          q.push(j);
        }
      }
    }
  }

  return false;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(h , -1 , sizeof h);
  cin >> n >> m;

  while(m --) {
    int a , b , c;
    cin >> a >> b >> c;
    add(a , b , c);
  }

  if(spfa()) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}


```

### 总结

1. `spfa`可以处理负权边，但是不能处理有负权回路的图
2. `Dijkstra`不能处理带有负权边和负权回路的图，因为在计算最短路径时，不会因为负边的出现而更新已经计算过的顶点的路径长度
3. `bellman-ford`可以处理任意带负权边和负权环的图，`spfa`可以处理带负权的图，`Dijkastra`只能处理带正权边的图

# 动态规划

## 背包问题

### 01 背包

[01 背包](https://www.acwing.com/problem/content/2/)

![Screenshot_20230401_111315_com.newskyer.draw.jpg](https://img1.imgtp.com/2023/04/01/1sfFYXe1.jpg)

1. 朴素版

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int , int>;
const int N = 1010;
int v[N] , w[N] , f[N][N] , n , m , dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

  for(int i = 1; i <= n; i ++)
    for(int j = 0; j <= m; j ++) {
      f[i][j] = f[i - 1][j];
      if(j >= v[i]) f[i][j] = max(f[i - 1][j] , f[i - 1][j - v[i]] + w[i]);
    }

  cout << f[n][m] << endl;

  return 0;
}

```

2. 优化一维版

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int , int>;
const int N = 1010;
int v[N] , w[N] , f[N][N] , n , m , dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

  for(int i = 1; i <= n; i ++)
    for(int j = m ; j >= v[i]; j --)
      dp[j] = max(dp[j] , dp[j - v[i]] + w[i]);

  cout << dp[m] << endl;

  return 0;
}

```

#### 关于一维优化

将二维转化成了一维：

删掉了第一维：在前`i`个物品中取

`dp[j]`表示：拿了总体积不超过`j`物品

#### 为什么能转化成一维

二维时的更新方式: `f[i][j] = max(f[i - 1][j] , f[i - 1][j - v[i]] + w[i])`

1. 我们发现，对于每次循环的下一组`i`，只会用到`i - 1`来更新当前值，不会用到`i - 2`及之前的值，于是可以在这次更新的时候，将原来的更新掉，反正以后也用不到，所以对于`i`的更新，只需要用到一个数组，直接覆盖就行了
2. 我们发现，对于每次`j`的更新，只需要用到之前`i - 1`时的`j`或者`j - v[i]`，不会用到后面的值

所以为了防止串着改，我们采取从后往前更新的方式，用原来`i - 1`的数组来更新`i`

如果从前往后更新的话，前面的更新过后，会接着更新后面的值，这样就不能保证是用原来`i - 1`的数组来更新`i`的了

##### 如何转化成一维

> 只用一个数组，每次都覆盖前面的数组

1. 如果当前位置的东西不拿的话，和前一位置的信息(原来`i - 1`数组这个位置上的值)是相同的，所以不用改变
2. 如果当前位置的东西拿了的话，需要和前一位置的信息(原来`i - 1`数组这个位置上值)取`max`

所以更新的方式就是`dp[j] = max(dp[j] , dp[j - v[i]] + w[i])`

整个更新的方式就相当于：每次`i++`，就从后往前覆盖一遍`dp`数组，每个位置上的值是否更新

### 完全背包

[完全背包](https://www.acwing.com/problem/content/description/3/)

![完全背包.png](https://img1.imgtp.com/2023/04/30/9lwuxlAA.png)

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int , int>;

const int N = 1010;
int f[N][N];
int n , m;
int v[N] , w[N];
int dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

  // for(int i = 1; i <= n; i ++)
  //   for(int j = 0; j <= m ; j ++) {
  //     //NOTE: 朴素版的写法
  //     // for(int k = 0; k * v[i] <= j; k ++)
  //     //   f[i][j] = max(f[i - 1][j] , f[i - 1][j - v[i] * k] + w[i] * k);
  //     //NOTE: 第一次优化
  //     // f[i][j] = f[i - 1][j];
  //     // if(j >= v[i]) f[i][j] = max(f[i][j] , f[i][j - v[i]] + w[i]);
  //
  //   }
  // cout << f[n][m] << endl;

  //NOTE: 第二次优化
  for(int i = 1; i <= n; i ++)
    for(int j = v[i]; j <= m; j ++)
      dp[j] = max(dp[j] , dp[j - v[i]] + w[i]);

  cout << dp[m] << endl;

  return 0;
}
```

#### 优化问题

![完全背包优化.png](https://img1.imgtp.com/2023/04/30/VjvwWQuN.png)

### 多重背包问题

[朴素版](https://www.acwing.com/problem/content/4/)
[优化版](https://www.acwing.com/problem/content/5/)

1. 朴素写法

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int , int>;
const int N = 1010;
int n , m;
int w[N] , v[N] , s[N];
int f[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 1; i <= n; i ++)
    cin >> v[i] >> w[i] >> s[i];

  for(int i = 1; i <= n; i ++)
    for(int j = 0; j <= m; j ++)
      for(int k = 0; k <= s[i] && k * v[i] <= j; k ++)
        f[i][j] = max(f[i][j] , f[i - 1][j - v[i] * k] + w[i] * k);

  cout << f[n][m];

  return 0;
}
```

2. 优化版
   > 二进制法

```c++

```

### 分组背包问题

[分组背包](https://www.acwing.com/problem/content/9/)

1. 朴素版

```c++

```

2. 优化版

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int , int>;
const int N = 110;
int w[N][N] , s[N] , v[N][N];
int n , m;
int f[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 1; i <= n; i ++) {
    cin >> s[i];
    for(int j = 0; j < s[i]; j ++) cin >> v[i][j] >> w[i][j];
  }

  for(int i = 1; i <= n; i ++)
    for(int j = m; j >= 0; j --)
      for(int k = 0; k <= s[i]; k ++)
        if(j >= v[i][k]) f[j] = max(f[j] , f[j - v[i][k] ] + w[i][k]);

  cout << f[m];

  return 0;
}

```

## 线性 DP

[数字三角形](https://www.acwing.com/problem/content/description/900/)

![数字三角形.png](https://img1.imgtp.com/2023/05/02/05Z3Z0Ll.png)

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int , int>;
const int N = 510 , INT = -1e9;
int mp[N][N] , f[N][N];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 1; i <= n; i ++) 
    for(int j = 1; j <= i; j ++)
      cin >> mp[i][j];

  for(int i = 0; i <= n; i ++)
    for(int j = 0; j <= i + 1; j ++) f[i][j] = INT; // NOTE: 初始化的时候要比题目给的边界多一，在找最大值的时候会用到一些不存在的点

  f[1][1] = mp[1][1];

  for(int i = 2; i <= n; i ++) 
    for(int j = 1; j <= i; j ++) 
      f[i][j] = max(f[i - 1][j - 1] + mp[i][j] , f[i - 1][j] + mp[i][j]);

  int res = INT;
  for(int i = 1; i <= n; i ++)
    res = max(res , f[n][i]);

  cout << res << endl;
  
  return 0;
}


```
