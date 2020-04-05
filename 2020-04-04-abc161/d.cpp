#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  int k;
  cin >> k;

  queue<ll> q;
  rep(i, 9) {
    q.push(i+1);
  }
  ll ans;
  rep(i, k) {
    ans = q.front(); q.pop();
    ll t = ans % 10;
    ll x = ans * 10;

    if( t != 0 ) {
      q.push(x + t - 1);
    }
    q.push(x + t);
    if( t != 9 ) {
      q.push(x + t + 1);
    }
  }
  cout << ans << endl;

  return 0;
}
