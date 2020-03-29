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

vector<int> f(const vector<vector<P> >& m, int src) {
  vector<int> d(m.size(), 1<<30);
  queue<P> q;
  q.push(P(src, 0));

  while(!q.empty()) {
    P t = q.front();
    q.pop();

    int dst = t.F;
    int c = t.S;
    if (d[dst] > c) {
      d[dst] = c;
      rep(i, m[dst].size()) {
        P n = m[dst][i];
        q.push(P(n.F, c + n.S));
      }
    }
  }

  return d;
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<vector<P> > m(n);
  rep(i, n-1) {
    m[i].push_back(P(i+1, 1));
    m[i+1].push_back(P(i, 1));
  }
  m[x-1].push_back(P(y-1, 1));
  m[y-1].push_back(P(x-1, 1));

  vector<int> v(n, 0);
  rep(i, n-1) {
    vector<int> d = f(m, i);
    for(int j = i+1; j < d.size(); j++) {
      v[d[j]]++;
    }
  }

  for(int i = 1; i < n; i++) {
    cout << v[i] << endl;
  }

  return 0;
}
