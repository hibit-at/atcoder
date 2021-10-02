#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const ll mod = 998244353;
const ll inf = 1e18;

void print_vector_vector(vector<vector<ll>> vv) {
  for (vector<ll> v : vv) {
    for (int i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

void print_to(vector<vector<int>> to) {
  int n = to.size();
  rep(i, n) {
    cout << "from " << i << " : to ";
    for (int next : to[i]) {
      cout << next << ",";
    }
    cout << endl;
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
  vector<vector<int>> notTo(n + 1, vector<int>(0));
  rep(i, n + 1) { notTo[i].push_back(i); }
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    notTo[u].push_back(v);
    notTo[v].push_back(u);
  }
  dp[0][1] = 1;
  rep(i, k) {
    ll all_now = 0;
    rep1(from, n) {
      all_now += dp[i][from];
      all_now %= mod;
    }
    rep1(now, n) {
      dp[i+1][now] += all_now;
      for (int from : notTo[now]) {
        dp[i+1][now] -= dp[i][from];
        dp[i+1][now] += mod;
        dp[i+1][now] %= mod;
      }
    }
  }
  cout << dp[k][1] << endl;
}