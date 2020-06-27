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

  vector<int> cnt(n+1, 0);
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j += i) {
      cnt[j] += 1;
    }
  }

  ll res = 0;
  for(int i = 1; i <= n; i++) {
    res += ll(cnt[i]) * i;
  }

  cout << res << endl;

  return 0;
}
