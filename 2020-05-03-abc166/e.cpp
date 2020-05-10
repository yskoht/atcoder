#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), v(n, 0);
  rep(i, n) {
    cin >> a[i];
    int t = i + a[i] + 1;
    if(t < n) {
      v[t] += 1;
    }
  }

  ll res = 0;
  rep(i, n) {
    int t = i - a[i] + 1;
    if(t >= 0) {
      res += v[t];
    }
  }

  cout << res << endl;

  return 0;
}
