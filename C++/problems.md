# 题目类型

## 坐标偏移量
> 利用坐标偏移量来处理题目
> 省略四个判断

[蛇形矩阵](https://www.acwing.com/problem/content/758/)

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
[走迷宫](https://www.acwing.com/problem/content/846/)


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
## 结构体排序
> 实现方式
> bool函数(cmp)
> 运算符重载

[分数线划定](https://www.luogu.com.cn/problem/P1068)


```bool cmp```


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
