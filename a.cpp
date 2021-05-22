#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

const ll mod = (ll)1e9 + 7;

ll rpow(ll a, ll r, ll mod) {
  if (r == 0)
    return 1;
  ll ans = rpow(a, r / 2, mod);
  ans *= ans;
  ans %= mod;
  if (r % 2 == 1)
    ans *= a;
  ans %= mod;
  return ans;
}

int main() {
  int k;
  cin >> k;
  if(k%9 != 0){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> dp(k + 1, 0);
  dp[0] = 1;
  rep1(i, k) {
    rep(j, min(i + 1, 10)) {
      dp[i] += dp[i - j];
      dp[i] %= mod;
    }
  }
  cout << dp[k] << endl;
  rep1(i,k){
    cout << rpow(2,i-1,mod) << "," << dp[i] << "..." << rpow(2,i-1,mod) - dp[i] << endl;
  }
}