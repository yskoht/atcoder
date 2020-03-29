#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

// n C x: n個からx個選ぶパターン数
int choose(int n, int x) {
  int p = 1, q = 1;
  rep(i, x) {
    p *= (n - i);
    q *= (i + 1);
  }
  return p / q;
}

int main() {
  int n, m;
  cin >> n >>m;

  int res = 0;
  if (n >= 2) res += choose(n, 2);
  if (m >= 2) res += choose(m, 2);

  cout << res << endl;

  return 0;
}
