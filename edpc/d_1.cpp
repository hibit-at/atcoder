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

const int inf = 2e9;

void chmax(ll &a, ll b) { a = max(a, b); }

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

int main() {
  int n, W;
  cin >> n >> W;
  vector<item> items(n);
  rep(i, n) {
    int w,v;
    cin >> w >> v;
    items[i].weight = w;
    items[i].value = v;
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));
  dp[0][0] = 0;
  rep(kind, n) {
    rep(weight, W + 1) {
      chmax(dp[kind + 1][weight], dp[kind][weight]);
      int next_weight = weight + items[kind].weight;
      if (next_weight > W) {
        continue;
      }
      chmax(dp[kind + 1][next_weight], dp[kind][weight] + items[kind].value);
    }
  }
  cout << dp[n][W] << endl;
}