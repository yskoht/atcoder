#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  deque<char> d;
  int q, t, f;
  char c;
  bool k = false;

  cin >> s;
  rep(i, s.size()) d.push_back(s[i]);

  cin >> q;
  rep(i, q) {
    cin >> t;
    if (t == 1) {
      k = !k;
    }
    else {
      cin >> f >> c;
      if (f == 1) {
        if(k) d.push_back(c);
        else d.push_front(c);
      }
      else {
        if(k) d.push_front(c);
        else d.push_back(c);
      }
    }
  }
  string ans = "";
  rep(i, d.size()) ans += d[i];
  if(k) reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}
