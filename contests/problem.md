# Atcoder

## ABC 310

### A - Order Something Else

#### 题意

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

### B - Strictly Superior

#### 题意

给出$N$种物品，给出三个筛选条件要同时满足，物品的属性有价格$P$，$M$种功能

条件：

1. 第j个物品大于等于第i个物品的价格
2. 第j个物品有第i个物品的所有功能
3. 第j个物品小于第i个物品的价格**_或者_**第j个物品比第i个物品多一个或者多个功能

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

### C - Reversible

#### 题意

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
