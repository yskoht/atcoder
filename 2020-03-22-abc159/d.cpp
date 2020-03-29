#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

map<P, ll> m;

// n C x: n個からx個選ぶパターン数
ll choose(int n, int x) {
  if (m.find(P(n, x)) != m.end()) return m[P(n, x)];

  ll p = 1, q = 1;
  rep(i, x) {
    p *= (n - i);
    q *= (i + 1);
  }

  return m[P(n, x)] = p / q;
}

int main() {
  int n;
  cin >> n;

  vector<int> as(n);
  rep(i, n) cin >> as[i];

  map<int, int> m1;
  rep(i, n) {
    int a = as[i];
    if (m1.find(a) == m1.end()) m1[a] = 0;
    m1[a]++;
  }

  ll sum = 0;
  auto it = m1.begin();
  while(it != m1.end()) {
    int k = it->F;
    int c = it->S;
    sum += choose(c, 2);
    it++;
  }

  rep(i, n) {
    int a = as[i];
    ll res = sum;

    if (m1.find(a) != m1.end()) {
      res -= choose(m1[a], 2);
      if (m1[a] - 1 >= 2) {
        res += choose(m1[a] - 1, 2);
      }
    }
    cout << res << endl;
  }

  return 0;
}
