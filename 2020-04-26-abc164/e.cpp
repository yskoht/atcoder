#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<ll,ll>;
using PP = pair<ll, P>;

class S {
  public:
    ll cur;
    ll s;
    ll t;

    S(ll c_, ll s_, ll t_) : cur(c_), s(s_), t(t_) {}

    bool operator < (const S& s) const {
      return this->t > s.t;
    };
};

int main() {
  ll n, m, s;
  cin >> n >> m >> s;
  vector<vector<PP>> edge(n);

  rep(i, m) {
    ll u, v, a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    edge[u].push_back(PP(v, P(a, b)));
    edge[v].push_back(PP(u, P(a, b)));
  }

  vector<P> ex(n);
  rep(i, n) {
    ll c, d;
    cin >> c >> d;
    ex[i] = P(c, d);
  }

  const ll s_max = 5000;

  const ll inf = 1e18;
  vector<vector<ll>> res(n, vector<ll>(s_max + 1, inf));

  priority_queue<S> q;
  s = min(s, s_max);
  q.push(S(0, s, 0));
  while(!q.empty()) {
    S t = q.top(); q.pop();
    ll tc = t.cur;
    ll ts = t.s;
    ll tt = t.t;

    if(res[tc][ts] <= tt) continue;
    res[tc][ts] = tt;

    ll c = ex[tc].F;
    ll d = ex[tc].S;

    {
      ll ns = ts + c;
      ll nt = tt + d;
      if(ns < s_max) {
        q.push(S(tc, ns, nt));
      }
    }

    rep(j, edge[tc].size()) {
      ll next = edge[tc][j].F;
      ll a = edge[tc][j].S.F;
      ll b = edge[tc][j].S.S;

      ll ns = ts - a;
      ll nt = tt + b;

      if(ns < 0) continue;
      if(ns >= s_max) continue;
      if(res[next][ns] <= nt) continue;
      q.push(S(next, ns, nt));
    }
  }

  for(ll i = 1; i < n; i++) {
    ll r = inf;
    rep(j, res[i].size()) {
      r = min(res[i][j], r);
    }
    cout << r << endl;
  }

  return 0;
}
