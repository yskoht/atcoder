#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

struct Hoge {
  int x, y, c;
  Hoge(int _x, int _y, int _c) : x(_x), y(_y), c(_c) {}
  bool operator < (const Hoge& a) const {
    return c > a.c;
  }
};

int main() {
  int h, w;
  int ch, cw;
  int dh, dw;

  cin >> h >> w;
  cin >> ch >> cw;
  cin >> dh >> dw;

  ch--; cw--;
  dh--; dw--;

  vector<string> t(h);
  vector<vector<int>> v(h, vector<int>(w, -1));
  rep(i, h) cin >> t[i];

  priority_queue<Hoge> que;

  que.push(Hoge(cw, ch, 0));
  while(!que.empty()) {
    Hoge cur = que.top();
    que.pop();

    int x = cur.x;
    int y = cur.y;
    int c = cur.c;

    // cout << x << ' ' << y << ' ' << c << endl;
    if(v[y][x] != -1) continue;
    v[y][x] = c;

    int dx[] = { 0, 1, 0, -1, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2 };
    int dy[] = { -1, 0, 1, 0, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
    int dc[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    rep(i, 28) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nc = c + dc[i];

      if(nx < 0 || nx >= w) continue;
      if(ny < 0 || ny >= h) continue;
      if(t[ny][nx] != '.') continue;
      if(v[ny][nx] != -1) continue;

      // cout << "-> " << nx << ' ' << ny << ' ' << nc << endl;

      que.push(Hoge(nx, ny, nc));
    }
  }

  // rep(y, h) {
  //   rep(x, w) {
  //     cout << v[y][x] << ' ';
  //   }
  //   cout << endl;
  // }

  cout << v[dh][dw] << endl;
  return 0;
}
