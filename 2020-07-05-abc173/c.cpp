#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int h, w, k;

int f(int yy, int xx, vector<string> t) {
  int cnt = 0;
  rep(y, h) {
    if ((yy >> y) & 1) {
      rep(x, w) {
        if ((xx >> x) & 1) {
          if (t[y][x] == '#') {
            cnt += 1;
          }
        }
      }
    }
  }

  return cnt;
}

int main() {
  cin >> h >> w >> k;

  vector<string> tab(h);
  rep(i, h) {
    cin >> tab[i];
  }

  int res = 0;
  rep(yy, 1 << h) {
    rep(xx, 1 << w) {
      int t = f(yy, xx, tab);
      if (t == k) {
        res += 1;
      }
    }
  }

  cout << res << endl;
  return 0;
}
