#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second
using namespace std;
using ll = long long;
using P = pair<int,int>;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

mint choose(int n, int x) {
  mint p = 1, q = 1;
  rep(i, x) {
    p *= (n - i);
    q *= (i + 1);
  }
  return p / q;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  mint sum = mint(2).pow(n) - 1 - comb(n, a) - comb(n, b);
  cout << sum.x << endl;
  return 0;
}
