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
  - [CodeForces](#codeforces) - [Round 886(Div 4)](#round-886div-4) - [D. Balanced Round](#d-balanced-round) - [Round 888(Div 3)](#round-888div-3) - [A. Escalator Conversations](#a-escalator-conversations) - [B. Parity Sort](#b-parity-sort) - [C. Tiles Comeback](#c-tiles-comeback) - [Educational Codeforces Round 152 (Rated for Div. 2)](#educational-codeforces-round-152-rated-for-div-2) - [C. Binary String Copying](#c-binary-string-copying) - [Codeforces Round 889 (Div. 2)](#codeforces-round-889-div-2) - [B. Longest Divisors Interval](#b-longest-divisors-interval)
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

### ABC314

#### C - Rotate Colored Subsequence

题解：

1. 首先需要二维数组把每个数对应的下标存好。
2. 建立一个新字符串遍历即可。

```c++
const int N = 200001;
int c[N];

void solve() {
  string s;
  int n , m;
  cin >> n >> m;
  cin >> s;
  vector<vector<int>> p(N);

  for(int i = 0; i < n; i++) cin >> c[i];
  for(int i = 0; i < n; i++) p[c[i]].emplace_back(i);

  string ans(n , '$');
  for(int i = 1; i <= m; i++) {
    int k = p[i].size();
    for(int j = 0; j < k; j++) ans[p[i][(j + 1) % k]] = s[p[i][j]];
  }
  cout << ans << '\n';

}
```

#### D - LOWER

题解：

这题如果直接模拟肯定会超时，所以关键在于我们在记录操作的时候，开一个`pair<int, char>`数组，来记录当前字符被修改的时间点

1. 如果当`t==1`，我们需要把当前的时间点记录下来。
2. 如果是剩下两种全局操作，只需要记录最后一次的操作以及时间点。

最后在输出答案的时候，只需要判断当前的字符的时间点是否大于全局操作的时间点，如果大于直接输出，否则按要求变成大小写就行。

时间复杂度$O(N + Q)$

```c++
const int N = 5e5 + 10;
using pic = pair<int , char>;
void solve() {
  int n , q;
  string S;
  cin >> n >> S >> q;
  vector<pic> vis(n);
  for(int i = 0; i < n; i++) {
    vis[i] = {0 , S[i]};
  }

  optional<pic> fill = nullopt;
// NOTE:
//类模板 std::optional 管理一个可选的容纳值，即可以存在也可以不存在的值。
//一种常见的 optional 使用情况是一个可能失败的函数的返回值。与其他手段，如 std::pair<T,bool> 相比， optional 良好地处理构造开销高昂的对象，并更加可读，因为它显式表达意图。
  for(int i = 0; i < q; i++) {
    int t , x;
    string c;
    cin >> t >> x >> c;
    if(t == 1) {
      vis[--x] = make_pair(i , c[0]);
    } else {
      fill = make_pair(i , t);
    }
  }

  for(auto& [time , c] : vis) {
    if(!fill.has_value() || time >= fill->first) { // NOTE: 如果没有全局操作或者当前时间点>=全局操作的时间点
      cout << c;
    } else if(fill->second == 2) {
      cout << static_cast<char>(tolower(c));
    } else {
      cout << static_cast<char>(toupper(c));
    }
  }

  cout << '\n';
}

```

### ABC323

### C World Tour Finals

> 题解

这题在求需要多少题才满足条件的时候忽略了找的题必须是没有做过的题才可行（写的时候完全忽略了这点）

```c++
void solve() {
    int N , M;
    std::cin >> N >> M;
    std::vector<int> A(M);
    for(auto& x : A) {
        std::cin >> x;
    }

    std::vector<std::string> s(N);
    std::vector<int> score(N);
    for(int i = 0; i < N; i++) {
        std::cin >> s[i];
        for(int j = 0; j < M; j++) {
            if(s[i][j] == 'o') {
                score[i] += A[j];
            }
        }
    }

    std::vector<int> p(N); // NOTE:根据A数组从大到小排序求下标。
    std::iota(p.begin() , p.end() , 0);
    std::sort(p.begin() , p.end() ,
              [&](int i , int j) {
                return A[i] > A[j];
              });

    for(int i = 0; i < N; i++) {
        int mx = 0;
        for(int j = 0; j < N; j++) {
            if(i != j) { // NOTE:求除了当前选手之外分数的最大值
                mx = std::max(score[j] + j + 1 , mx);
            }
        }

        int cur = score[i] + i + 1 , ans = 0;
        for(auto j : p) {
            // NOTE:如果当前这题是没解决的并且当前分数是小于最大值的，ans++，更新当前值。
            if(s[i][j] == 'x' && cur <= mx) {
                cur += A[j];
                ans++;
            }
        }

        std::cout << ans << "\n";
    }

```

#### D Merge Slimes

> 题解

这题直接贪就ok了，开一个map存每个尺寸的史莱姆来有多少个，算答案的时候把个数大于2的史莱姆用map继续存，直到map为空的时候就行了

```c++
void solve() {
    int N;
    std::cin >> N;
    std::map<ll , ll> mp;
    while(N--) {
        ll S , C;
        std::cin >> S >> C;
        mp[S] = C;
    }

    ll ans = 0;
    while(!mp.empty()) {
        auto[s , c] = *mp.begin();
        mp.erase(mp.begin());
        ans += c % 2;
        if(c >= 2) {
            mp[s * 2] += c / 2;
        }
    }

    std::cout << ans << "\n";
}

```

### ABC324

#### C

> 题解

这题主要是在看$T{'}$是否是添加还是删除了元素，原本想的是用`unordered_map`来对比s串，后面发现只要`s`串从前往后比遍历，在第一个两个串元素不一样的地方停止，$T{'}$串从后往前遍历，算两个位置加起来的总长度是否大于长度最长的串就行

```c++
void solve() {
    int n;
    std::string t;
    std::cin >> n >> t;
    std::vector<std::string> a( n );
    for ( auto &x : a ) {
        std::cin >> x;
    }

    auto similar = [&](const std::string&a , const std::string& b){
        if(abs((int)a.size() - (int)b.size()) > 1) {
            return false;
        }

        if(a == b) return true;
        size_t l = 0 , r = 0;
        while(l < a.size() && l < b.size() && a[l] == b[l]) {
            l++;
        }
        while(r < a.size() && r < b.size() && a.end()[-1 - r] == b.end()[-1 - r]) {
            r++;
        }

        return l + r >= std::max(a.size() , b.size()) - 1;
    };
    std::vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(similar(a[i] , t)) {
            ans.emplace_back(i + 1);
        }
    }

    std::cout << ans.size() << std::endl;
    for(auto x : ans) {
        std::cout << x << " ";
    }
}

```

### D

> 题解

题目是要看当前序列的幂次方总和是否是某一个数的平方，问这样的数有几个  

如果有一个数满足这样的序列，那这个数必小于等于$10{N}$，只需要去找这样的数有几个即可

```c++
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::sort(s.begin() , s.end());

    int ans = 0;
    ll max_value = pow(10 , n);
    for(ll i = 0; i * i <= max_value; i++) {
        auto t = std::to_string(i * i);// 将当前数转换成字符串
        t.resize(n , '0'); // 保证两个串长度一样，不足地方补0
        std::sort(t.begin(), t.end());
        if(s == t) {
            ans++;
        }
    }

    std::cout << ans << "\n";
    
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

### 搜索综合练习

#### A - 最短路计数

思路：由于题目不存在负边权，所以可以用`Dijkstra`来求最短路径，在更新最短路径的时候，如果发现当前遍历到的点的下一个点的距离是和当前这个点的距离是一样的，可以将当前这个点有有多少种方案并起来即可。

```c++
#define mod 100003


void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for(int i = 0; i < m; i++) {
        int u , v;
        cin >> u >> v;
        u--, v--;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    vector<bool> vis(n);
    vector<int> dist(n , 0x3f3f3f3f);
    vector<int> ans(n);
    dist[0] = 0;
    ans[0] = 1;
    queue<pii> q;
    q.emplace(0 , 0);
    while(q.size()) {
        auto[distance , node] = q.front();
        q.pop();
        if(vis[node]) continue;
        vis[node] = true;

        for(auto j : a[node]) {
            if(dist[j] > dist[node] + 1) {
                dist[j] = dist[node] + 1;
                q.emplace(dist[j] , j);
                ans[j] = ans[node];
            }
            else if(dist[j] == dist[node] + 1) {
                ans[j] += ans[node];
                ans[j] %= mod;
            }
        }
    }

    for(auto x : ans) {
        cout << x << '\n';
    }
}

```

### B - 八数码难题

思路：开一个字符串来存最终的状态，在进行状态转移的过程中，我们需要把一维数组的坐标转换成二维数组的坐标，这样在将`0`字符换到其他位置会方便点。同时开一个哈希表来存储每种状态的步骤数。

```c++
void solve() {
    string end = "123804765";

    unordered_map<string , int> dist;
    string st;
    cin >> st;

    queue<string> q;
    q.emplace(st);
    dist[st] = 0;

    while(q.size()) {
        auto t = q.front();
        q.pop();

        int ans = dist[t];
        if(t == end) {
            cout << ans << '\n';
            break;
        }

        int k = t.find('0');
        int x = k / 3 , y = k % 3;
        for(int i = 0; i < 4; i++) {
            int x1 = x + dx[i] , y1 = y + dy[i];
            if(x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3) {
                swap(t[k] , t[x1 * 3 + y1]);
                if(!dist.count(t)) {
                    dist[t] = ans + 1;
                    q.emplace(t);
                }
                swap(t[k] , t[x1 * 3 + y1]);
            }
        }


    }
}
```

### F - 费解的开关

思路：

1. 先枚举第一行的点击方法，总共有32种，完成第一行的点击之后，锁定第一行的状态
2. 接着由第一行的状态去递推出第二行的状态，依次类推。
3. 如果最后一行不全为0，说明这种点击状态不合法。
4. 在所有合法的状态中选择点击次数最少的那一种。

```c++

0


constexpr int dx[] = {0 , -1 , 0 , 1 , 0};
constexpr int dy[] = {0 , 0 , 1 , 0 , -1};

void solve() {
    vector<string> a(5);
    vector<string> backup(5);
    int res = 10;
    for(auto& x : backup) cin >> x;

    function<void(int , int)> turn = [&](int x , int y)->void{
        for(int i = 0; i < 5; i++) {
            int x1 = x + dx[i] , y1 = y + dy[i];
            if(x1 < 0 || x1 >= 5 || y1 < 0 || y1 >= 5) continue;
            a[x1][y1] ^= 1;
        }
    };

    for(int op = 0; op < 32; op++) {
        int cnt = 0;
        a = backup;
        //NOTE: 操纵第一行的开关
        for(int j = 0; j < 5; j++) {
            if(op >> j & 1) {
                turn(0 , j);
                cnt++;
            }
        }
        //NOTE: 递推出第1～4行开关的状态
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 5; j++)
                if(a[i][j] == '0') {
                    turn(i + 1 , j);
                    cnt++;
                }

        bool ok = true;
        for(int i = 0; i < 5; i++)
            if(a[4][i] == '0') ok = false;
        if(ok && res > cnt) res = cnt;
    }

    if(res > 6) res = -1;
    cout << res << '\n';
}
```

## 树和二叉树练习

### C - FBI 树

思路：从题目可以知道，这棵二叉树其实是已经建好的。我们只需要按后续遍历的方式将二叉树遍历一边就行了。

```c++
void solve() {
  int n;
  cin >> n;
  n = 1 << n;
  string s;
  cin >> s;
  vector<node> a;
  function<char(string)> judge = [&](string pre){
    if(pre.find('0') != string::npos && pre.find('1') != string::npos) return 'F';
    else if(pre.find('0') != string::npos) return 'B';
    else return 'I';
  };

  function<void(string)> build = [&](string s){
    if(s.size() > 1) {
      build(s.substr(0 , s.size() / 2));
      build(s.substr(s.size() / 2));
    }

    char ans = judge(s);
    cout << ans;

  };
  build(s);
}
```

### G - 合并果子

思路：这题其实是个huffman树，只需要用小根堆来存储所需要的最小体力值即可。

```c++
void solve() {
  priority_queue<int , vector<int> , greater<int>> Heap;
  int n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    Heap.emplace(x);
  }
  int res = 0;

  while(Heap.size() > 1) {
    int a = Heap.top();
    Heap.pop();
    int b = Heap.top();
    Heap.pop();
    res += (a + b);
    Heap.emplace(a + b);
  }

  cout << res << '\n';
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

### Codeforces Round 903(div3)

#### A

> 题解

暴力枚举字符串`x`的长度直到`x`的长度大于等于`2 * m`，此时`x`不会因为长度问题而找不到`s`，如果在枚举之后仍找不到`s`则输出`-1`

```c++
void solve() {
    int n , m;
    std::cin >> n >> m;
    std::string x , s;
    std::cin >> x >> s;
    int ans = 0;
    while(x.find(s) == std::string::npos && (x.size() < 2 * m || ans == 0)) {
        ans++;
        x += x;
    }

    if(x.find(s) != std::string::npos) {
        std::cout << ans << "\n";
    } else {
        std::cout << "-1\n";
    }
}
```

#### B

> 题解 解法一：

要是每个元素都相等，先进行排序，要使得$a == b == c$，`b`和`c`必须是`a`的倍数。因为操作最多有三次，意味着最多分出3个`a`，最后$a == b == c$，所以`a`总的有6个，`b + c`最多有5个a

```c++
void solve() {
    std::vector<int> a(3);
    for(auto& x : a) {
        std::cin >> x;
    }
    std::sort(a.begin() , a.end());

    if(a[1] % a[0] == 0 && a[2] % a[0] == 0 && (a[2] + a[1]) / a[0] <= 5) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}
```

> 解法二

枚举每一种切法，如果发现可以整除，并且操作数小于等于3，就直接输出YES

```c++
void solve() {
    int a, b , c;
    std::cin >> a >> b >> c;

    int cnt = 0;

    for(auto x : {a , a / 2 , a / 3 , a / 4}) {
        if(x == 0) {
            continue;
        }

        bool ok = true;
        for(auto y : {a , b , c}) {
            if(y % x != 0) {
                ok = false;
                break;
            }
            cnt += y / x - 1;
        }

        if(ok && cnt <= 3) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}
```

#### C

> 题解

给定长度为n的二维正方形字符。  
对于任一个位置，可以将其修改为**相邻、更大**的元素，代价为1，如`a`修改为`b`。如果字符为`z`，则无法修改

如果二维矩阵顺时针翻转90度之后，和原来的相同，那么称其为完美矩阵

问，需要最少多少修改代价，使其成为完美矩阵。

枚举左上的$\frac{1}{4}$块，找出旋转位置对应的四个位置，记录字母出现的次数。

题目的操作是一次操作把字母+1，最多到z

所以最少的操作是把四个字母都变成最大的字母。

```c++
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for(auto& x : a) {
        std::cin >> x;
    }

    int res = 0;
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n / 2; j++) {
            int sum = a[i][j] + a[j][ n - 1 - i] + a[n - 1 - j][i] + a[n - 1 - i][n - 1 - j];
            int mx = std::max({a[i][j] , a[j][n - 1 - i] , a[n - 1 - j][i] , a[n - 1 - i][n - 1 - j]});
            res += 4 * mx - sum;
        }
    }

    std::cout << res << "\n";
}

```

#### D

> 题解

给定一个数组

- 每次可以选择2个不同元素$a_i , a_j$
- 找$a_i$的因数$x$，令$a_i = \frac{a_i}{x} , a_j = a_j * x$

执行上述操作任一次，问能否让所有元素相等。

求所有质因子，看它们的幂次是否能整除n

```c++

```

#### E
