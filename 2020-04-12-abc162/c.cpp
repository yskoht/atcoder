#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

// GCD, LCM
// https://youtu.be/8lm8o8L9Bmw?t=2285
// https://youtu.be/XI8exXVxZ-Q?t=3595
// https://youtu.be/F2p_e6iKxnk?t=843
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll ngcd(const vector<ll>& a){
  ll res;
  res = a[0];
  for(int i = 1; i < a.size() && res != 1; i++) {
    res = gcd(a[i], res);
  }
  return res;
}
ll nlcm(const vector<ll>& numbers) {
  ll res;
  res = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    res = lcm(res, numbers[i]);
  }
  return res;
}

int main() {
  int k;
  cin >> k;

  ll res = 0;
  for(int a = 1; a <= k; a++) {
    for(int b = 1; b <= k; b++) {
      for(int c = 1; c <= k; c++) {
        vector<ll> v = {a, b, c};
        res += ngcd(v);
      }
    }
  }
  cout << res << endl;

  return 0;
}
