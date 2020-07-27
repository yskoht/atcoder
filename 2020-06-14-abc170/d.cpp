#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

const int N = 1000001;

int main() {
  int n;
  cin >> n;

  vector<int> v(N, false);
  vector<int> tab(N, false);
  rep(i, n) {
    int t;
    cin >> t;
    if (v[t]) {
      tab[t] = true;
    }
    v[t] = true;
  }

  rep(i, N) {
    if (!v[i]) continue;

    for(int j = i * 2; j < N; j += i) {
      v[j] = false;
    }
  }

  rep(i, N) {
    if (tab[i]) {
      v[i] = false;
    }
  }

  cout << count(v.begin(), v.end(), true) << endl;

  return 0;
}
