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

  cin >> n >> s;

  int as[n], ts[n], gs[n], cs[n];
  int ap = 0;
  int tp = 0;
  int gp = 0;
  int cp = 0;
  rep(i, n) {
    if(s[i] == 'A') ap += 1;
    if(s[i] == 'T') tp += 1;
    if(s[i] == 'G') gp += 1;
    if(s[i] == 'C') cp += 1;
    as[i] = ap;
    ts[i] = tp;
    gs[i] = gp;
    cs[i] = cp;
  }

  int cnt = 0;
  rep(i, n) {
    for(int j = i+1; j < n; j++) {
      int a = as[j] - as[i];
      if(s[i] == 'A') a += 1;

      int t = ts[j] - ts[i];
      if(s[i] == 'T') t += 1;

      int g = gs[j] - gs[i];
      if(s[i] == 'G') g += 1;

      int c = cs[j] - cs[i];
      if(s[i] == 'C') c += 1;

      if(a == t && g == c) {
        cnt += 1;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
