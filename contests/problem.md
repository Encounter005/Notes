# 比赛题目

<!--toc:start-->
- [比赛题目](#比赛题目)
  - [Atcoder](#atcoder)
    - [ABC 310](#abc-310)
      - [A - Order Something Else](#a-order-something-else)
      - [B - Strictly Superior](#b-strictly-superior)
      - [C - Reversible](#c-reversible)
    - [ABC 311](#abc-311)
      - [C - Find it](#c-find-it)
      - [D - Grid Ice Floor](#d-grid-ice-floor)
    - [ABC 312](#abc-312)
      - [C - Invisible Hand](#c-invisible-hand)
  - [vjudge](#vjudge)
    - [枚举算法](#枚举算法)
      - [D - Division](#d-division)
    - [STL练习-vector、stack、queue](#stl练习-vectorstackqueue)
      - [圆桌问题](#圆桌问题)
      - [简单计算器](#简单计算器)
  - [nowcoder](#nowcoder)
    - [“多校联赛” 第一次](#多校联赛-第一次)
  - [CodeForces](#codeforces)
    - [Round 886(Div 4)](#round-886div-4)
      - [D. Balanced Round](#d-balanced-round)
    - [Round 888(Div 3)](#round-888div-3)
      - [A. Escalator Conversations](#a-escalator-conversations)
      - [B. Parity Sort](#b-parity-sort)
      - [C. Tiles Comeback](#c-tiles-comeback)
    - [Educational Codeforces Round 152 (Rated for Div. 2)](#educational-codeforces-round-152-rated-for-div-2)
      - [C. Binary String Copying](#c-binary-string-copying)
    - [Codeforces Round 889 (Div. 2)](#codeforces-round-889-div-2)
      - [B. Longest Divisors Interval](#b-longest-divisors-interval)
<!--toc:end-->

## Atcoder

### ABC 310

#### A - Order Something Else

题意：给出N个物品的价格以及一种价钱$P$还有一个折扣$Q$，取N个物品中最小的价格加上折扣和$P$进行比较，取最小值

AC code

```c++
void solve() {
  int n , p , q;
  cin >> n >> p >> q;
  int ans = p;
  for(int i = 0; i < n; i ++) {
    int d;
    cin >> d;
    ans = min(ans , q + d);
  }

  cout << ans << '\n';
}


```

#### B - Strictly Superior

题意：给出$N$种物品，给出三个筛选条件要同时满足，物品的属性有价格$P$，$M$种功能

条件：

1. 第j个物品大于等于第i个物品的价格
2. 第j个物品有第i个物品的所有功能
3. 第j个物品小于第i个物品的价格**或者**第j个物品比第i个物品多一个或者多个功能

AC code

```c++

void solve() {
  int n , m;
  cin >> n >> m;
  vector<int> P(n);
  vector<bitset<100>> F(n); // NOTE: 这里用二进制序列来存储每个物品的功能

  for(int i = 0; i < n; i ++) {
    cin >> P[i];
    int C;
    cin >> C;
    while(C --) {
      int x;
      cin >> x;
      F[i][x - 1] = 1;
    }
  }

  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      if(P[i] <= P[j] && (F[i] & F[j]) == F[j] && (P[i] < P[j] || F[i] != F[j])) {
        cout << "Yes\n";
        return;
      }
    }
  }

  cout << "No\n";
}

```

#### C - Reversible

题意：给$N$个字符串，将这个序列进行去重，当第j个字符串等于第i个字符串的反转，这种情况被认为是相同的。

```c++

void solve() {
  int n;
  cin >> n;
  vector<string> S(n);

  for(auto &x : S) {
    cin >> x;
    auto T = x;
    reverse(T.begin() , T.end());
    x = min(T , x);
  }

  sort(S.begin() , S.end()); // NOTE: 因为要使用unique函数，所以要先排序
  cout << unique(S.begin() , S.end()) - S.begin() << endl;
}


```

### ABC 311

#### C - Find it

题意：写这道题的时候，题目读错了，以为是要求最大的环，其实只要输出任意一个环就好了。

题解：用链表的遍历方式，之后从尾节点开始往前遍历，直到再一次碰到尾节点结束。

```c++

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> vis(n);
  for(auto& x : a) {
    cin >> x;
    x--;
  }

  int i = 0;
  while(!vis[i]) {
    vis[i] = true;
    i = a[i];
  }

  int j = i;
  vector<int> ans;
  do {
    ans.push_back(j);
    j = a[j];
  } while(j != i);

  cout << ans.size() << '\n';
  for(auto x : ans) cout << x + 1 << ' ';
}


```

#### D - Grid Ice Floor

题意：给一个图，`#`表示岩石 ， `.`表示冰，运动员起始位置在$(2 , 2)$，问运动员能碰到多少个冰

题解：看数据范围，可以用`dfs`来解决，但是看大佬是`bfs` ;-;

```c++

constexpr int dx[] = {-1 , 0 , 1 , 0};
constexpr int dy[] = {0 , 1 , 0 , -1};


void solve() {
  int N , M;
  cin >> N >> M;
  vector<string> grid(N);
  for(auto& i : grid) cin >> i;

  vector<vector<bool>> vis(N , vector<bool>(M)); // NOTE: 防止有的点被走过两遍
  vector<vector<bool>> pass(N , vector<bool>(M)); // NOTE: 记录所有能走到的点

  vis[1][1] = true; // NOTE:标记起点
  pass[1][1] = true;
  queue<pii> q;
  q.emplace(1 , 1);

  while(!q.empty()) {
    auto [x , y] = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int ddx = dx[i] + x , ddy = dy[i] + y;
      while(grid[ddx][ddy] == '.') {
        pass[ddx][ddy] = true;
        ddx += dx[i];
        ddy += dy[i];
      }
      ddx -= dx[i];
      ddy -= dy[i];

      if(!vis[ddx][ddy]) {
        vis[ddx][ddy] = true;
        q.emplace(ddx , ddy);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++)
      ans += pass[i][j];
  }

  cout << ans << '\n';
}

```

### ABC 312

#### C - Invisible Hand

题意：给定义一个卖家序列和一个买家序列，求一个$x$使得能够卖出去的人数大于等于能买的人数。

题解：

1. 假设价钱是 0 ，那么一开始就有M个买家会买，0个卖家会卖。然后价钱每次变成下一个后，要么买家不买了，要么卖家开始卖，所以他们两个的差值就会减少1，所以第M位就是差值相等的地方

```c++
void solve() {
  int n , m;
  cin >> n >> m;
  vector<int> a(n + m);
  for(int i = 0 ; i < n; i++) cin >> a[i];
  for(int i = n; i < n + m; i++) {
    cin >> a[i];
    a[i]++;
  }

  nth_element(a.begin() , a.begin() + m - 1 ,a.end());

  cout << a[m - 1] << '\n';
}


```

2. 通过二分答案来找到这个最小的x

```c++
bool check(int& mid , vector<int>& a , vector<int>& b) {
  int c1 = 0 , c2 = 0;
  for(auto x : a)
    if(mid >= x) c1++;

  for(auto x : b)
    if(mid <= x) c2++;

  return c1 >= c2;
}


void solve() {
  int n , m;
  cin >> n >> m;
  vector<int> a(n) , b(m);
  for(auto& x : a) cin >> x;
  for(auto& x : b) cin >> x;

  int l = 1 , r = *max_element(b.begin() , b.end());

  while(l <= r) {
    int mid = (l + r) >> 1;
    if(check(mid , a , b)) {
      r = mid - 1;
    } else l = mid + 1;
  }

  cout << l << '\n';
}



```

## vjudge

### 枚举算法

#### D - Division

题意：

有两个数$abcde$和$fghij$，它们满足一种公式

$$
\frac{abcde}{fghij} = n
$$

其中$abcde$和$fghij$这两个数每位上数字都不相同

现在给一个数$N$，求`abcde`和`fghij`

AC code

```c++
void solve() {
  int n, k = 0;
  char buf[99];
  while (cin >> n && n) {
    bool ok = false;
    if (k++) puts("");
    for (int i = 1234; i <= 98765; i++) {
      int res = i * n;
      sprintf(buf, "%05d%05d", res, i); // NOTE:将答案输出到字符串
      if (strlen(buf) > 10) // NOTE: 如果结果位数大于10,则答案不合法
        break;
      sort(buf, buf + 10);

      bool isok = true;
      for (int i = 0; i < 10; i++) {
        if (buf[i] != i + '0')
          isok = false;
      }

      if (isok) {
        ok = true;
        printf("%05d / %05d = %d\n", res, i, n);
      }
    }
    if (!ok) {
      printf("There are no solutions for %d.\n", n);
    }
  }
}
```

### STL练习-vector、stack、queue

#### 圆桌问题

[圆桌问题](https://vjudge.net/problem/HDU-4841)

题解：模拟杀死坏人的过程，每次删掉位置`pos`的人， $pos = (pos + m - 1) % n$

```c++
void solve() {
  int n , m;
  while(cin >> n >> m) {
    vector<int> a(n * 2);
    iota(a.begin() , a.end() , 0);

    int pos = 0;
    for(int i = 0; i <  n; i++) {
      pos = (pos + m - 1) % a.size();
      a.erase(a.begin() + pos);
    }

    int j = 0;
    for(int i = 0; i < 2 * n; i++) {
      if(!(i % 50) && i) cout << '\n';
      if(i == a[j] && j < a.size()) {
        cout << 'G';
        j++;
      } else {
        cout << 'B';
      }
    }
    cout << "\n\n";
  }
}
```

#### 简单计算器

[简单计算器](https://vjudge.net/contest/569311#problem/C)

题解：用scanf来处理操作符和数字，用`stack`来存储当前的计算结果，最后求`stack`里面所有元素的总和

```c++
void solve() {
  char c;
  db a;
  while(~scanf("%lf%c", &a , &c)) { // NOTE:数字+空格

    if(a == 0 && c == '\n') break;
    stack<db> stk;
    double ans = 0;
    stk.push(a);
    while(scanf("%c %lf" , &c , &a)) {// NOTE:空格+数字
      if(c == '+') {
        stk.push(a);
      } else if(c == '-') {
        stk.push(-a);
      } else if(c == '*') {
        db s = stk.top() * a;
        stk.pop();
        stk.push(s);
      } else if(c == '/') {
        db s = stk.top() / a;
        stk.pop();
        stk.push(s);
      }
      char k = getchar(); // NOTE:删掉当前数字后面的空格
      if(k == '\n') break;
    }

    while(!stk.empty()) {
      ans += stk.top();
      stk.pop();
    }
    printf("%.2lf\n" , ans);
  }
}
```

## nowcoder

### “多校联赛” 第一次

[K-Subdivision](https://ac.nowcoder.com/acm/contest/57355/K)

题意：
给定一个无向图$G(n , m)$，可以将其中任意一条边分裂成一条长度为任意的链（向边中插入任意多个点），可以操作任意次（也可以不操作）。问经过这样处理后，从1号节点出发，至多走$K$步最多可以到多少个节点。

题解：

先从1号点开始`bfs`，同时求出每个点到1号点的最短距离，考虑分裂的边在哪里
考虑选什么边来加点，两种情况：

1. 删除该边不影响任何一个点到1的最短距离。如何寻找这样的边，若一个点到1的最短距离小于等于$K$且该点有2个以上的出度/入度，则存在出度/入度减2的这样的边。
2. 删除该边影响某点到1的最短路，那么这样的整一段最多为答案提供$K$的贡献

![nowcoder-duoxiao01-K.png](https://img1.imgtp.com/2023/07/18/xDuZ472I.png)

结论：

对于从1号节点开始的路径$P_i = \{1 , v_1 , v_2 , ..... , v_n\}$，如果需要分裂边以增加点数，那么在增加点数相同的情况下，分裂$( v_{n-1} , v_n)$ 最优

AC code

```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m , k;
    cin >> n >> m >> k;
    vector<vector<int>> node(n);
    vector<int> deg(n);

    for(int i = 0; i < m; i ++) {
        int u , v;
        cin >> u >> v;
        u-- , v--;
        node[u].emplace_back(v);
        node[v].emplace_back(u);
        deg[u]++ , deg[v]++;
    }

    vector<int> dis(n , -1);
    dis[0] = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        auto T = q.front();
        q.pop();

        for(auto j : node[T]) {
            if(dis[j] == -1) {
                dis[j] = dis[T] + 1;
                q.push(j);
            }
        }
    }


    using ll = long long;
    ll ans = k * deg[0] + 1;
    for(int i = 1; i < n; i ++) {
        if(deg[i] >= 2 && dis[i] != -1 && dis[i] <= k) {
            ans += 1LL * (k - dis[i]) * (deg[i] - 2);
        }
    }

    cout << ans << endl;
    return 0;
}
```

## CodeForces

### Round 886(Div 4)

#### D. Balanced Round

[D. Balanced Round](https://codeforces.com/contest/1850/problem/D)

题意：给出一个序列，一个标准差值$K$，问最少要多少次操作能保证这个序列相邻两个元素的差不大于$K$

思路：双指针，其中一个$l$指向序列的起始位置，另一个指针$r$自加，当发现第$r$和$r-1$个元素的差是大于$K$，算出$l -> r$的距离，取$max$并且更新$l$的值。

> 最开始想的是差分，其实这题纯模拟就对了:D

```c++
void solve() {
  int n , k;
  cin >> n >> k;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  sort(a.begin() , a.end());
  int l = 0 , ans = 0;
  for(int r = 1; r <= n; r++) {
    if(r == n || a[r] - a[r - 1] > k) {
      ans = max(r - l , ans);
      l = r;
    }
  }
  cout << n - ans << '\n';
}


```

### Round 888(Div 3)

#### A. Escalator Conversations

题解： 只要$1 \le {abs(H - h_i)\over k} \ge m - 1$即可，并且$abs(H - h_i)$必须是K的倍数

```c++
void solve() {
  int n , m , k , H;
  cin >> n >> m >> k >> H;
  vector<int> a(n);
  for(auto& x : a) {
    cin >> x;
    x = abs(H - x);
  }
  print(a);
  int cnt = 0;
  for(auto& x : a) {
    if(x % k == 0 && (x / k) < m && x != 0) cnt++;
  }

  cout << cnt << '\n';
}
```

#### B. Parity Sort

题解：由于奇数和偶数的位置在排序后依旧和原来一样，所以只需要奇数排序，偶数排序，然后奇数按顺序放入所有奇数本来所占的位置，偶数也一样，然后判断一下是不是非递减即可

```c++
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  priority_queue<int , vector<int> , greater<int>> b , c;
  for(auto& x : a) {
    cin >> x;
    if(x & 1) b.emplace(x);
    else c.emplace(x);
  }

  for(int i = 0; i < n; i++) {
    if(a[i] & 1) {
      a[i] = b.top();
      b.pop();
    } else {
      a[i] = c.top();
      c.pop();
    }

    if(i && a[i] < a[i - 1]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";

}
```

#### C. Tiles Comeback

题解：只要有k个和第1个颜色相同的点（包括第1个），然后在这k个再往后有k个和最后一个颜色相同的点（包括最后一个）即可。如果第一个和最后一个颜色相同，只要有k个颜色相同颜色的点即可

```c++
void solve() {
  int n , k;
  cin >> n >> k;
  vector<int> a(n);
  for(auto& x : a) cin >> x;

  if(a[0] == a[n - 1]) {
    if(count(a.begin() , a.end() , a[0]) >= k) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }

  int c1 = 0 , c2 = count(a.begin() , a.end() , a[n - 1]);
  for(int i = 0; i < n; i++) {
    c1 += (a[0] == a[i]);
    c2 -= (a[n - 1] == a[i]);
    if(c1 >= k && c2 >= k) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}
```

### Educational Codeforces Round 152 (Rated for Div. 2)

#### C. Binary String Copying

题解：

1. 对区间$[l , r]$，如果区间已经有序等于没有操作。
2. 对于一个区间，显然前缀的0和后缀的1是没用的，所以我们只需找到第一个1的位置`L`，最后一个0的位置`R`，其实等价于给$[L , R]$排序，用`set`维护以下这种等价类有多少种即可。

```c++
void solve() {
  string op;
  int n , m ;
  cin >> n >> m;
  cin >> op;
  set<pii> S;
  vector<int> lst(n + 1 , -1) , nxt(n + 1 , n);

  for(int i = n - 1; i >= 0; i--) {
    nxt[i] = op[i] == '1' ? i : nxt[i + 1];
  }

  for(int i = 0; i < n; i++) {
    lst[i + 1] = op[i] == '0' ? i : lst[i];
  }


  while(m--) {
    int l , r;
    cin >> l >> r;
    l--;
    l = nxt[l];
    r = lst[r];

    if(l > r) {
      l = r = -1;
    }
    S.emplace(l , r);
  }

  cout << S.size() << '\n';
}

```

### Codeforces Round 889 (Div. 2)

#### B. Longest Divisors Interval

题解：

先举个例子：  
6 ： 1 2 3  
12： 1 2 3 4  
20： 1 2 （4 5）  
30： 1 2 3  
40: 1 2 (4 5)  
100: 1 2 (4 5)

`括号中为另一组满足题意的解`

我们猜想，假设一个数字能找到一个连续被整除的区间$[l , r]$，那一定对应存在等长的区间$[1 , r - l + 1]$同样满足题意

所以从1开始遍历到第一个不能被整除的数字即可。

```c++
void solve() {
  ll n;
  cin >> n;
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(n % i) break;
    cnt++;
  }
  cout << cnt << '\n';
}
```
