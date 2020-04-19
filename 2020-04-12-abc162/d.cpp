#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;

  cin >> n;
  cin >> s;

  vector<int> r(n), g(n), b(n);
  rep(i, n) {
    if (i == 0) {
      r[i] = g[i] = b[i] = 0;
      if (s[i] == 'R') r[i] = 1;
      if (s[i] == 'G') g[i] = 1;
      if (s[i] == 'B') b[i] = 1;
    }
    else {
      r[i] = r[i-1];
      g[i] = g[i-1];
      b[i] = b[i-1];
      if (s[i] == 'R') r[i] = r[i-1] + 1;
      if (s[i] == 'G') g[i] = g[i-1] + 1;
      if (s[i] == 'B') b[i] = b[i-1] + 1;
    }
  }
  reverse(s.begin(), s.end());
  reverse(r.begin(), r.end());
  reverse(g.begin(), g.end());
  reverse(b.begin(), b.end());

  ll res = 0;
  rep(i, n - 2) {
    for(int j = i+1; j < n - 1; j++) {
      if (s[j] == s[i]) continue;
      char sk;
      if (s[i] == 'R' && s[j] == 'G') sk = 'B';
      else if (s[i] == 'R' && s[j] == 'B') sk = 'G';
      else if (s[i] == 'G' && s[j] == 'R') sk = 'B';
      else if (s[i] == 'G' && s[j] == 'B') sk = 'R';
      else if (s[i] == 'B' && s[j] == 'R') sk = 'G';
      else if (s[i] == 'B' && s[j] == 'G') sk = 'R';

      int ij = j - i;
      int cnt = 0;
      if (sk == 'R') cnt = r[j+1];
      if (sk == 'G') cnt = g[j+1];
      if (sk == 'B') cnt = b[j+1];
      int k = j + ij;
      if (k <= n - 1 && s[j + ij] == sk && cnt > 0) cnt -= 1;
      res += cnt;
    }
  }
  cout << res << endl;

  return 0;
}
