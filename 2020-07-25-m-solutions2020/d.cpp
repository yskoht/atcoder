#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<ll,ll>;
using PP = pair<P, P>;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n+1, 0);
  rep(i, n) {
    cin >> arr[i];
  }

  ll res = 1000;
  queue<PP> que;
  que.push(PP(P(1000, 0), P(0, 0)));

  vector<ll> memo(n+1, -1);

  vector<bool> tab(n, false);
  rep(i, n) {
    bool f = false;
    for(int j = i+1; j < n; j++) {
      if (arr[i] < arr[j]) {
        f = true;
        break;
      }
    }
    tab[i] = f;
  }

  while(!que.empty()) {
    PP t = que.front();
    que.pop();

    ll m = t.F.F;
    ll s = t.F.S;
    ll d = t.S.F;
    ll b = t.S.S;

    if (memo[d] > m + s * arr[d]) continue;
    memo[d] = m + s * arr[d];

    if (m > res) {
      res = m;
    }
    if (d + 1 > n) {
      continue;
    }

    que.push(PP(P(m, s), P(d+1, b)));
    if(m >= arr[d] && tab[d]) {
      ll k = m / arr[d];
      que.push(PP(P(m - arr[d] * k, s + k), P(d+1, arr[d])));
    }
    if(s > 0 && arr[d] > arr[d+1] && arr[d] > b) {
      que.push(PP(P(m + arr[d] * s, 0), P(d+1, 0)));
    }
  }

  cout << res << endl;


  return 0;
}
