#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int inf = 1<<29;

int main()
{
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  s += '0';

  int n = s.size();
  vector< vector<int> > dp(n+1, vector<int>(2, inf));
  dp[0][0] = 0;

  for(int i = 0; i < n; i++) {
    for(int a = 0; a < 10; a++) {
      for(int j = 0; j < 2; j++) {
        int d = s[i] - '0';
        int aa = a - j;
        int b = aa - d;
        int nj = 0;
        if(b < 0) {
          b += 10;
          nj = 1;
        }
        dp[i+1][nj] = min(dp[i+1][nj], dp[i][j] + a + b);
      }
    }
  }

  cout << dp[n][0] << endl;
}
