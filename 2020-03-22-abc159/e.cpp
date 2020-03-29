#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

vector<int> hsplit(int hstate, int h) {
  vector<int> a;
  a.push_back(0);

  rep(i, h) {
    if ((hstate >> i) & 1 == 1) {
      a.push_back(i + 1);
    }
  }
  a.push_back(h);

  return a;
}

bool wsplit(int wi, const vector<int>& hs, const vector<int>& ws, const vector<string>& s, int k) {
  int left = ws[ws.size() - 1];
  int right = wi;

  bool f = true;
  rep(i, hs.size() - 1) {
    int top = hs[i];
    int bottom = hs[i+1];

    int cnt = 0;
    for(int y = top; y < bottom; y++) {
      for(int x = left; x < right; x++) {
        if (s[y][x] == '1') {
          cnt += 1;
        }
      }
    }

    if (cnt > k) {
      f = false;
      break;
    }
  }

  return f;
}

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  int ans = 1<<30;

  rep(hstate, 1<<(h-1)) {
    vector<int> hs = hsplit(hstate, h);
    vector<int> ws;
    ws.push_back(0);

    bool f = true;
    for(int wi = 1; wi <= w; wi++) {
      bool ok = wsplit(wi, hs, ws, s, k);
      if (ok == false) {
        if (wi == 1) {
          f = false;
          break;
        }

        ws.push_back(wi - 1);
        ok = wsplit(wi, hs, ws, s, k);
        if (ok == false) {
          f = false;
          break;
        }
      }
    }
    if (f) {
      int t = hs.size() - 2 + ws.size() - 1;
      ans = min(ans, t);
    }
  }
  cout << ans << endl;
  return 0;
}
