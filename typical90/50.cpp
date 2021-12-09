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

const ll inf = 1e18;
const ll mod = (ll)1e9 + 7;

int main() {
  int n, l;
  cin >> n >> l;
  vector<ll> dp(3e6, 0);
  dp[0] = 1;
  rep(i, n) {
    dp[i + 1] += dp[i];
    dp[i + 1] %= mod;
    dp[i + l] += dp[i];
    dp[i + l] %= mod;
  }
  cout << dp[n] << endl;
}