#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  int n, p;
  cin >> n >> p;

  string s;
  cin >> s;

  if(p == 2 || p == 5) {
    ll res = 0;
    for(int i = n - 1; i >= 0; i--) {
      int t = s[i] - '0';
      if(t % p == 0) {
        res += i + 1;
      }
    }
    cout << res << endl;
    return 0;
  }

  vector<int> v(n+1, 0);
  int d = 1;
  for(int i = n - 1; i >= 0; i--) {
    int t = s[i] - '0';
    int m = (t * d) % p;
    v[i] = (v[i + 1] + m) % p;
    d = (10 * d) % p;
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
