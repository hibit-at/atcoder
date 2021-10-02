#include <algorithm>
#include <iomanip>
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
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

class item {
public:
  int weight;
  int value;
  item() {}
  item(int weight, int value) {
    this->weight = weight;
    this->value = value;
  }
};

void chmax(ll &a, ll b) { a = max(a, b); }
int n, W;
vector<item> items(101);
vector<vector<ll>> dp(101,vector<ll>(1e5+1,-1));

ll dfs(int kind, int weight) {
  if (kind < 0 || weight < 0) {
    return 0;
  }
  if (dp[kind][weight] > -1) {
    return dp[kind][weight];
  }
  ll ans = 0;
  int item_weight = items[kind - 1].weight;
  int from_weight = weight - item_weight;
  if (kind > 0 && from_weight >= 0) {
    ll item_value = items[kind - 1].value;
    chmax(ans, dfs(kind - 1, from_weight) + item_value);
  }
  chmax(ans, dfs(kind - 1, weight));
  chmax(ans, dfs(kind, weight - 1));
  return dp[kind][weight] = ans;
}

int main() {
  cin >> n >> W;
  dp[0][0] = 0;
  rep(i, n) {
    int w, v;
    cin >> w >> v;
    items[i].weight = w;
    items[i].value = v;
  }
  cout << dfs(n, W) << endl;
}