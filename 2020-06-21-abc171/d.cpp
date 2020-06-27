#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  map<int, int> m;
  ll sum = 0;

  int t, n;
  cin >> n;
  rep(i, n) {
    cin >> t;
    m[t]++;
    sum += t;
  }

  int q, b, c;
  cin >> q;
  rep(i, q) {
    cin >> b >> c;
    sum -= ll(m[b]) * ll(b);
    sum += ll(m[b]) * ll(c);
    m[c] += m[b];
    m[b] = 0;
    printf("%lld\n", sum);
  };

  return 0;
}
