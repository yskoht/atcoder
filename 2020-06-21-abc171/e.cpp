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
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
  }

  vector<int> res(n, 0);
  rep(i, 32) {
    int cnt = 0;
    rep(j, n) {
      int t = (v[j] >> i) & 1;
      cnt += t;
    }
    if (cnt % 2 == 0) {
      rep(j, n) {
        int t = (v[j] >> i) & 1;
        res[j] |= (t << i);
      }
    } else {
      rep(j, n) {
        int t = (v[j] >> i) & 1;
        t = (t == 0) ? 1 : 0;
        res[j] |= (t << i);
      }
    }
  }

  rep(i, n) {
    if (i) cout << ' ';
    cout << res[i];
  }
  cout << endl;

  return 0;
}
