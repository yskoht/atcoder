
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n, -1);
  vector<vector<int>> edge(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  queue<int> q;
  v[0] = 0;
  q.push(0);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    rep(i, edge[now].size()) {
      int next = edge[now][i];
      if(v[next] != -1) continue;

      v[next] = now;
      q.push(next);
    }
  }

  bool f = true;
  rep(i, v.size()) {
    if(v[i] == -1) {
      f = false;
      break;
    }
  }
  if (f == false) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for(int i = 1; i < n; i++) {
      cout << v[i] + 1 << endl;
    }
  }

  return 0;
}
