#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> ps(a), qs(b), rs(c);
  rep(i, a) cin >> ps[i];
  rep(i, b) cin >> qs[i];
  rep(i, c) cin >> rs[i];

  sort(ps.rbegin(), ps.rend());
  sort(qs.rbegin(), qs.rend());

  vector<int> v;
  rep(i, x) v.push_back(ps[i]);
  rep(i, y) v.push_back(qs[i]);
  rep(i, rs.size()) v.push_back(rs[i]);
  sort(v.rbegin(), v.rend());

  ll res = 0;
  rep(i, x + y) res += v[i];
  cout << res << endl;

  return 0;
}
