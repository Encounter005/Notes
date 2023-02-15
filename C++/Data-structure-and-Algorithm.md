# 数据结构
<!--toc:start-->
- [数据结构](#数据结构)
  - [目录](#目录)
  - [链表](#链表)
  - [静态链表](#静态链表)
    - [单链表](#单链表)
    - [双链表](#双链表)
  - [栈](#栈)
    - [数组模拟](#数组模拟)
    - [单调栈](#单调栈)
  - [队列](#队列)
    - [数组模拟](#数组模拟)
    - [单调队列](#单调队列)
  - [Trie树](#trie树)
  - [并查集](#并查集)
  - [堆](#堆)
    - [小根堆](#小根堆)
    - [大根堆](#大根堆)
    - [堆的存储](#堆的存储)
    - [如何手写一个堆](#如何手写一个堆)
  - [哈希表](#哈希表)
    - [存储结构](#存储结构)
        - [1. 开放寻址法](#1-开放寻址法)
        - [2. 拉链法](#2-拉链法)
    - [字符串哈希方式](#字符串哈希方式)
- [算法](#算法)
  - [排序](#排序)
    - [快速排序](#快速排序)
    - [归并排序](#归并排序)
    - [堆排序](#堆排序)
  - [高精度运算](#高精度运算)
    - [高精度加法](#高精度加法)
    - [高精度减法](#高精度减法)
    - [高精度乘法](#高精度乘法)
    - [高精度除法](#高精度除法)
  - [KMP算法](#kmp算法)
  - [位运算](#位运算)
  - [离散化](#离散化)
  - [双指针](#双指针)
  - [二分](#二分)
    - [整数二分](#整数二分)
    - [浮点数二分](#浮点数二分)
  - [前缀和](#前缀和)
    - [一维](#一维)
    - [二维](#二维)
  - [差分](#差分)
    - [一维](#一维)
    - [二维](#二维)
  - [区间合并](#区间合并)
- [数学知识](#数学知识)
  - [斐波那契数列写法](#斐波那契数列写法)
  - [找质数](#找质数)
  - [找最大公约数](#找最大公约数)
  - [找最小公倍数](#找最小公倍数)
- [搜索与图论](#搜索与图论)
  - [DFS(深度优先搜索) && BFS(宽度优先搜索)](#dfs深度优先搜索-bfs宽度优先搜索)
    - [BFS](#bfs)
    - [DFS](#dfs)
  - [树与图(有向图)](#树与图有向图)
    - [存储](#存储)
    - [深度优先遍历](#深度优先遍历)
    - [宽度优先遍历](#宽度优先遍历)
  - [拓补排序](#拓补排序)
<!--toc:end-->



## 目录


***






## 链表
![YwArL.png](https://c2.im5i.com/2023/01/01/YwArL.png)
![YwDjs.png](https://c2.im5i.com/2023/01/01/YwDjs.png)
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

>  生成链表
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
> 移除值为val的所有节点
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
[两个链表的第一个公共节点](200~https://www.acwing.com/problem/content/62/)
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

![YUWSz.jpeg](https://c2.im5i.com/2023/01/17/YUWSz.jpeg)

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
![YU286.jpeg](https://c2.im5i.com/2023/01/17/YU286.jpeg)

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
## Trie树

![YwHq8.png](https://c2.im5i.com/2023/01/01/YwHq8.png)

[Trie字符串统计](https://www.acwing.com/problem/content/837/)
[Trie存储整数](https://www.acwing.com/problem/content/145/)
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


![YwuL6.png](https://c2.im5i.com/2023/01/01/YwuL6.png)

[合并集合](https://www.acwing.com/problem/content/838/)

[连通块中点的数量](https://www.acwing.com/problem/content/839/)


> 将两个集合合并
> 询问两个元素是否在一个集合当中


```markdown
每一个集合用一棵树来表示
树根的编号就是整个集合的编号
每个节点存储它的父节点
p[x]表示x的父节点
```
> Q1：  如何判断树根： if(p[x] == x)
> Q2：如何求x的集合编号：while(p[x] != x) x = p[x]
> Q3：如何合并两个集合： p[x]是x的集合编号，p[y]是y的集合编号 p[x] = y;
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
![ROoHU.png](https://c2.im5i.com/2022/12/29/ROoHU.png)
### 大根堆
![ROnG8.png](https://c2.im5i.com/2022/12/29/ROnG8.png)
### 堆的存储
![RO3Lw.png](https://c2.im5i.com/2022/12/29/RO3Lw.png)

### 如何手写一个堆
1. 插入一个数  ``` heap[++ size] = x; up(size); ```
2. 求集合当中的最小值 ``` heap[1] ```
3. 删除最小值 ``` heap[1] = heap[size]; size --; down(1); ```
4. 删除任意一个元素 ``` heap[k] = heap[size]; size --; down(k); up(k); ```
5. 修改任意一个元素 ``` heap[k] = x; down(k); up(k); ```

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
![YF0K5.png](https://c2.im5i.com/2022/12/30/YF0K5.png)
1. 找大于最大值的一个质数
2. 插入 && 查找操作
> 先求哈希值 ```int k = (x % N + N) % N;```
> 将哈希值插入h[k]，如果这个点上有存，就换下一个，如果到末尾都有值，就从下标0的位置开始找
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
![YFoH3.png](https://c2.im5i.com/2022/12/30/YFoH3.png)
1. 找大于最大值的一个质数
2. 插入操作
> 先求哈希值 ```int k = (x % N + N) % N;```
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
> 比kmp好使
> 记录不能从0开始
![YSPG4.png](https://c2.im5i.com/2023/01/06/YSPG4.png)

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

## KMP算法
> next[]数组 -- 找到最长的模式串相等的前缀和后缀
> 快速匹配两个字符串


[kmp算法](https://www.acwing.com/problem/content/833/)
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
![YwoH7.jpeg](https://c2.im5i.com/2023/01/01/YwoH7.jpeg)
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

![YURw8.jpeg](https://c2.im5i.com/2023/01/17/YURw8.jpeg)

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
> 新建一个数组用于存储原数组的前n项和
![nwXML.png](https://c2.im5i.com/2023/02/02/nwXML.png)

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
![nwWoS.png](https://c2.im5i.com/2023/02/02/nwWoS.png)

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

## 区间合并

![YUXu5.jpeg](https://c2.im5i.com/2023/01/17/YUXu5.jpeg)
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
![Ygkuq.png](https://c2.im5i.com/2023/01/09/Ygkuq.png)

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
***


### DFS

> DFS
![YgOSt.png](https://c2.im5i.com/2023/01/09/YgOSt.png)


[排列数字](https://www.acwing.com/problem/content/844/)
[n皇后问题](https://www.acwing.com/problem/content/845/)

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
***

## 树与图(有向图)

> 树是一种特殊的图

![Y5r1y.png](https://c2.im5i.com/2023/01/20/Y5r1y.png)

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


***

### 深度优先遍历


![Y5ylO.png](https://c2.im5i.com/2023/01/20/Y5ylO.png)
![Y5B9R.png](https://c2.im5i.com/2023/01/20/Y5B9R.png)


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




## 拓补排序

