
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define F first
#define S second

using ll = long long;
using P = pair<int,int>;

vector<long long> prime_factorize(long long N) {
    vector<long long> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;

        // 割れる限り割り続ける
        while (N % a == 0) {
            N /= a;
        }

        // その結果を push
        res.push_back(a);
    }

    // 最後に残った数について
    if (N != 1) res.push_back(N);
    return res;
}

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
  int n;
  cin >> n;

  set<int> s;
  bool pairwise = true;
  vector<vector<int>> v;

  int N;
  cin >> N;
  ll g = N;

  rep(i, n-1) {
    cin >> N;
    g = gcd(g, N);

    vector<int> res;
    for (int a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        while (N % a == 0) {
            N /= a;
        }
        res.push_back(a);
    }
    if (N != 1) res.push_back(N);

    if(pairwise) {
      rep(j, res.size()) {
        if(s.count(res[j]) > 0) {
          pairwise = false;
          break;
        }
        s.insert(res[j]);
      }
    }
    v.push_back(res);
  }

  if(g == 1) {
    if(pairwise) {
      cout << "pairwise coprime" << endl;
    }
    else {
      cout << "setwise coprime" << endl;
    }
  } else {
    cout << "not coprime" << endl;
  }

  return 0;
}
