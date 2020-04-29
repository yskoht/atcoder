#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  const int p = 2019;

  string s;
  cin >> s;

  int n = s.size();
  vector<int> v(n+1, 0);
  int d = 1;
  for(int i = n-1; i >= 0; i--) {
    int t = s[i] - '0';
    int m = (t * d) % p;
    v[i] = (v[i + 1] + m) % p;
    d = (d * 10) % p;
  }

  vector<int> cnt(p, 0);
  ll res = 0;
  for(int i = n; i >= 0; i--) {
    res += cnt[v[i]];
    cnt[v[i]] += 1;
  }
  cout << res << endl;

  return 0;
}
