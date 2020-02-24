#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

const ll inf = ll(1e18) + 1;

int main() {
  ll n, k;

  cin >> n >> k;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  ll l = -inf;
  ll r = inf;

  while(l + 1 < r) {
    ll x = (l + r) / 2;
    ll t = 0;
    for(ll i = 0; i < n; i++) {
      if (a[i] < 0) {
        ll l2 = -1;
        ll r2 = n;
        while (l2 + 1 < r2) {
          ll x2 = (l2 + r2) / 2;
          if (a[i] * a[x2] < x) {
            r2 = x2;
          } else {
            l2 = x2;
          }
        }
        t += n - r2;
      } else {
        ll l2 = -1;
        ll r2 = n;
        while (l2 + 1 < r2) {
          ll x2 = (l2 + r2) / 2;
          if (a[i] * a[x2] < x) {
            l2 = x2;
          } else {
            r2 = x2;
          }
        }
        t += r2;
      }
      if (a[i] * a[i] < x) t -= 1;
    }

    if (t / 2 < k) {
      l = x;
    } else {
      r = x;
    }
  }
  cout << l << endl;

  return 0;
}

