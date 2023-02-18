# 题目类型

<!--toc:start-->
- [题目类型](#题目类型)
  - [宽度优先搜索(BFS)](#宽度优先搜索bfs)
    - [1. [蛇形矩阵](https://www.acwing.com/problem/content/758/)](#1-蛇形矩阵httpswwwacwingcomproblemcontent758)
    - [2. [走迷宫](https://www.acwing.com/problem/content/846/)](#2-走迷宫httpswwwacwingcomproblemcontent846)
    - [[树的遍历](https://www.acwing.com/problem/content/1499/)](#树的遍历httpswwwacwingcomproblemcontent1499)
      - [思路](#思路)
        - [如何有中序和后序确定一颗二叉树](#如何有中序和后序确定一颗二叉树)
      - [AC 代码](#ac-代码)
  - [结构体排序](#结构体排序)
  - [双指针算法](#双指针算法)
    - [1. [字符串删减](https://www.acwing.com/problem/content/3771/)](#1-字符串删减httpswwwacwingcomproblemcontent3771)
      - [思路](#思路)
      - [AC 代码](#ac-代码)
    - [2. [最长连续不重复子序列](https://www.acwing.com/problem/content/801/)](#2-最长连续不重复子序列httpswwwacwingcomproblemcontent801)
      - [思路](#思路)
      - [AC 代码](#ac-代码)
  - [递推](#递推)
    - [1. [砖块](https://www.acwing.com/problem/content/3780/)](#1-砖块httpswwwacwingcomproblemcontent3780)
      - [思路](#思路)
      - [AC 代码](#ac-代码)
<!--toc:end-->



## 宽度优先搜索(BFS)
> 利用坐标偏移量来处理题目
> 省略四个判断

### 1. [蛇形矩阵](https://www.acwing.com/problem/content/758/)

```c++
#include <iostream>
using namespace std;
const int N = 110;
int n, m, p[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
  int x = 0, y = 0, d = 1;

  for (int i = 1; i <= n * m; i++) {
    p[x][y] = i;
    int a = x + dx[d], b = y + dy[d];
    if (a < 0 || a >= n || b < 0 || b >= m || p[a][b]) {// 条件有p[a][b]表示这个点已经走过了，如果没走过是0为假
      d = (d + 1) % 4;
      a = x + dx[d], b = y + dy[d];
    }
    x = a, y = b;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << p[i][j] << ' ';
    cout << endl;
  }

  return 0;
}

```
### 2. [走迷宫](https://www.acwing.com/problem/content/846/)


```c++
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 110;
int p[N][N], d[N][N], n, m;
typedef pair<int, int> PII;

// d[][]表示当前点到起点的距离

queue<PII> q;

int bfs() {
  q.push({0, 0});//将起点放入容器

  int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
  memset(d, -1, sizeof(d));//初始化为-1,表示这个点还没用用过
  d[0][0] = 0;//初始化起点
  while (q.size()) {
    PII t = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && p[x][y] == 0) {
        d[x][y] = d[t.first][t.second] + 1;
        q.push({x, y});
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

### [树的遍历](https://www.acwing.com/problem/content/1499/)

![Screenshot_20230218_094238_com.newskyer.draw.jpg](https://img1.imgtp.com/2023/02/18/v9wg1l20.jpg)

#### 思路

##### 如何有中序和后序确定一颗二叉树

1. 后序遍历的最后一个点一定是该树或者子树的根节点
2. 中序遍历根的左右分左子树和右子树

因此可以先通过找到后序遍历中的最后一个点的值，然后再到中序序列找到根的位置``用哈希表来实现``，在将该树分为左子树和右子树不断递归，这样就可以重新构造一棵二叉树

#### AC 代码

```c++
 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
using namespace std;

const int N = 40;
int n;
unordered_map<int, int> l , r , pos; //存储每个点的左儿子、右儿子，在中序遍历里面每个值对应的下标
int postorder[N] , inorder[N]; //后序遍历 ， 中序遍历
queue<int> q;
int build(int il , int ir , int pl , int pr)
{
  int root = postorder[pr]; // 找到后序遍历中根节点的下标
  int k = pos[root]; // 通过哈希表找到中序遍历中根节点的下标

  if(il < k) l[root] = build(il , k - 1 ,pl ,k - 1 - il + pl); //找到左儿子
  if(ir > k) r[root] = build(k + 1 , ir , k - 1 - il + pl + 1 , pr - 1); // 找到右儿子

  return root;
}


void bfs(int root)
{
  q.push(root);
  while(q.size())
  {
    auto t = q.front();
    q.pop();
    cout << t << ' ';
    if(l.count(t)) q.push(l[t]); // 如果存在左儿子，就将左儿子入队
    if(r.count(t)) q.push(r[t]); // 如果存在右儿子，就将右儿子入队
  }
}


int main()
{
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> postorder[i];

  for(int i = 0; i < n; i ++)
  {
    cin >> inorder[i];
    pos[inorder[i]] = i;
  }

  int root = build(0 , n - 1 , 0 , n - 1); // 当前子树中序遍历的区间，后序遍历的区间
  bfs(root);
  return 0;
}

```


## 结构体排序
> 实现方式
> bool函数(cmp)
> 运算符重载

[分数线划定](https://www.luogu.com.cn/problem/P1068)




```c++
#include<iostream>
#include<algorithm>
using namespace std;

struct stu
{
    int num;
    int c , m , e;
    int sum;
}student[310];


bool cmp(stu a, stu b)
{
    if(a.sum != b.sum) return a.sum > b.sum;
    else
    {
        if(a.c != b.c) return a.c > b.c;
        else
        {
            if(a.num != b.num) return a.num < b.num;
        }
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        student[i].num = i;
        cin >> student[i].c >> student[i].m >> student[i].e;
        student[i].sum =  student[i].c + student[i].m + student[i].e;
    }

    sort(student + 1 , student + n + 1 , cmp);
    for(int i = 1; i <= 5; i ++) cout << student[i].num << ' ' << student[i].sum << endl;


    return 0;
}

```

```运算符重载```

```c++

#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;

struct Data {
  int x;
  double y;
  string z;

  bool operator<(const Data &t) { return x < t.x; }
} a[N];

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i].x >> a[i].y >> a[i].z;
  sort(a, a + n);

  for (int i = 0; i < n; i++)
    cout << a[i].x << ' ' << setiosflags(ios::fixed) << setprecision(2)
         << a[i].y << ' ' << a[i].z << ' ' << endl;
  return 0;
}
```

## 双指针算法

找到某种性质来优化暴力

### 1. [字符串删减](https://www.acwing.com/problem/content/3771/)

![Screenshot_20230217_084959_com.newskyer.draw.jpg](https://img1.imgtp.com/2023/02/17/OVsZSesj.jpg)

#### 思路
用一个指针`i`来遍历字符串，如果发现有一个字符是`x`，那就用另一个指针'j'来扫描'x'的个数，这样就得到了连续'x'有
$j - i$，考虑到如果只删掉一个'x'，后面会补上x的情况，所以必须删掉两个'x'

设连续的'x'字符串长度为k，则有

$ \begin{cases} K = i - j \\K \lt 3 , 0 \\ K \leq 3 , K - 2 \end{cases} $



#### AC 代码

```c++

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
using LL = long long;
using PII = pair<int , int>;
string str;
int k , n;
void solution()
{
  cin >> n >> str;

  for(int i = 0; i < n; i ++)
  {
    if(str[i] == 'x')
    {
      int j = i;
      while(j < n && str[j] == 'x') j ++;
      k += max(j - i - 2 , 0);
      i = j - 1;
    }
  }

  printf("%d" , k);
}
```

### 2. [最长连续不重复子序列](https://www.acwing.com/problem/content/801/)

![Screenshot_20230218_083534_com.newskyer.draw.jpg](https://img1.imgtp.com/2023/02/18/13ZISuLr.jpg)

#### 思路

用一个`a[]`来记录题目给的数据，用一个`s[]`来记录每个数据出现的次数，用i指针来遍历`a[]`,如果一个数据出现的次数大于1，j指针就往右移动一位，同时`s[a[j]] --`, `res`表示最长的子序列长度

#### AC 代码

```c++

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
using LL = long long;
using PII = pair<int , int>;
const int N = 1e5 + 10;
int n , a[N] , s[N];

int res;
void solution()
{
  cin >> n;
  int i = 0 , j = 0;
  for(i = 0 , j = 0; i < n; i ++)
  {
    cin >> a[i];
    s[a[i]] ++;
    while(s[a[i]] > 1 && j < n)
    {
      s[a[j]] --;
      j ++;
    }
    res = max(res , i - j + 1);
  }
  
  cout << res << endl;


}
```

## 递推

> 从已知到未知

### 1. [砖块](https://www.acwing.com/problem/content/3780/)

![Screenshot_20230218_081223_com.newskyer.draw.jpg](https://img1.imgtp.com/2023/02/18/XTac17uQ.jpg)

#### 思路
由题目得，对于每一组砖块是否要翻转，要看每组的第一个砖块的颜色是否与目标颜色一致，这题目的数据范围很小，所以可以枚举全是黑的情况和全是白的情况，并且这道题的最终结果就两种`黑或白`，另外操作顺序也是无影响的


#### AC 代码

```c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n ;
string str;

void up(char &c)
{
  if(c == 'W') c = 'B';
  else c = 'W';
}

bool check(char c)
{
  string s = str;
  vector<int> res;

  for(int i = 0; i + 1 < n; i ++)
  {
    if(s[i] != c)
    {
      up(s[i]);
      up(s[i + 1]);
      res.push_back(i);
    }

  }
    if(s.back() != c) return false;
    cout << res.size() << endl;
    for(auto x : res) cout << x + 1 << ' ';
    if(res.size()) cout << endl;
    return true;
}

int main()
{
  int T;
  cin >> T;
  while(T --)
  {
    cin >> n >> str;
    if(!check('B') && !check('W')) puts("-1");
  }

  return 0;
}

```
