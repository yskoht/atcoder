#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

struct Edge {
  int next;
  int cost;
  int time;
  Edge(){}
  Edge(int next, int cost, int time): next(next), cost(cost), time(time) {}
};

struct Status {
  int city;
  int money;
  ll time;
  Status (int city, int money, ll time): city(city), money(money), time(time) {}

  bool operator < (const Status& status) const {
    return this->time > status.time;
  }
};

int main() {
  const int s_max = 2500;
  const ll inf = 1e18;

  int n, m, s;
  cin >> n >> m >> s;

  vector<vector<Edge>> edges(n);
  rep(i, m) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--; v--;
    edges[u].emplace_back(v, a, b);
    edges[v].emplace_back(u, a, b);
  }

  vector<P> ex(n);
  rep(i, n) {
    int c, d;
    cin >> c >> d;
    ex[i] = P(c, d);
  };

  vector<vector<ll>> memo(n, vector<ll>(s_max+1, inf));
  priority_queue<Status> que;
  auto push = [&](int city, int money, ll time) {
    if(money < 0 || money >= s_max) return;
    if(memo[city][money] <= time) return;
    que.emplace(city, money, time);
  };

  s = min(s, s_max);
  que.emplace(0, s, 0);
  while(!que.empty()) {
    Status now = que.top(); que.pop();
    if(memo[now.city][now.money] <= now.time) continue;
    memo[now.city][now.money] = now.time;

    {
      int c = ex[now.city].F;
      int d = ex[now.city].S;

      int next_money = now.money + c;
      ll next_time = now.time + d;
      push(now.city, next_money, next_time);
    }

    for(Edge e: edges[now.city]) {
      int next_money = now.money - e.cost;
      ll next_time = now.time + e.time;
      push(e.next, next_money, next_time);
    }
  }

  for(int i = 1; i < n; i++) {
    cout << *min_element(memo[i].begin(), memo[i].end()) << endl;
  }

  return 0;
}
