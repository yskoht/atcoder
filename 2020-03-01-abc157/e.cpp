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

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}

  void init(int n) {
    this->n = n;
    d.clear();
    d.assign(n + 1, 0);
  }

  void add(int i, T x=1) {
    while(i < d.size()) {
      d[i] += x;
      i += (i & -i);
    }
  }
  T sum(int i) {
    T t = 0;
    while (i > 0) {
      t += d[i];
      i -= (i & -i);
    }
    return t;
  }
};

int main() {
  int n, q;
  string s;

  cin >> n;
  cin >> s;
  cin >> q;

  vector<BIT<int> > bits(26);
  rep(i, 26) {
    bits[i].init(n);
  }

  rep(i, n) {
    bits[s[i] - 'a'].add(i + 1, 1);
  }

  rep(_i, q) {
    int type;
    cin >> type;

    if (type == 1) {
      int i;
      char c;
      cin >> i >> c;
      i--;
      bits[s[i] - 'a'].add(i + 1, -1);
      s[i] = c;
      bits[s[i] - 'a'].add(i + 1, 1);
    } else {
      int l, r;
      cin >> l >> r;
      int res = 0;
      rep(i, 26) {
        int t = bits[i].sum(r) - bits[i].sum(l - 1);
        res += (t > 0);
      }
      printf("%d\n", res);
    }
  }

  return 0;
}
