# 比赛题目

<!--toc:start-->

- [比赛题目](#比赛题目)
  - [Atcoder](#atcoder)
    - [ABC 310](#abc-310)
      - [A - Order Something Else](#a-order-something-else)
        - [题意](#题意)
      - [B - Strictly Superior](#b-strictly-superior)
        - [题意](#题意)
      - [C - Reversible](#c-reversible)
        - [题意](#题意)
  - [vjudge](#vjudge)
    - [枚举算法](#枚举算法)
      - [D - Division](#d-division)
  - [nowcoder](#nowcoder) - [“范式杯” 第一次](#范式杯-第一次)
  <!--toc:end-->

## Atcoder

### ABC 310

#### A - Order Something Else

##### 题意

给出N个物品的价格以及一种价钱$P$还有一个折扣$Q$，取N个物品中最小的价格加上折扣和$P$进行比较，取最小值

AC code

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int , int>;

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

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}

```

#### B - Strictly Superior

##### 题意

给出$N$种物品，给出三个筛选条件要同时满足，物品的属性有价格$P$，$M$种功能

条件：

1. 第j个物品大于等于第i个物品的价格
2. 第j个物品有第i个物品的所有功能
3. 第j个物品小于第i个物品的价格**或者**第j个物品比第i个物品多一个或者多个功能

AC code

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int , int>;

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

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
```

#### C - Reversible

##### 题意

给$N$个字符串，将这个序列进行去重，当第j个字符串等于第i个字符串的反转，这种情况被认为是相同的。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int , int>;

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

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;

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

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}

```

## nowcoder

### “范式杯” 第一次

[K-Subdivision](https://ac.nowcoder.com/acm/contest/57355/K)

题解：

先从1号点开始`bfs`，同时求出每个点到1号点的最短距离。  
考虑选什么边来加点，两种情况：

1. 删除该边不影响任何一个点到1的最短距离。如何寻找这样的边，若一个点到1的最短距离小于等于$K$且该点有2个以上的出度/入度，则存在出度/入度减2的这样的边。
2. 删除该边影响某点到1的最短路，那么这样的整一段最多为答案提供$K$的贡献

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
