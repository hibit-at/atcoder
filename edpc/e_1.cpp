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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const int inf = 2e9;

void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(int &a, int b) { a = max(a, b); }

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

void print_vector_vector(vector<vector<ll>> vv) {
  for (vector<ll> v : vv) {
    for (ll i : v) {
      if (i == inf) {
        cout << "-,";
      } else {

        cout << i << ",";
      }
    }
    cout << endl;
  }
}

int main() {
  int n, W;
  cin >> n >> W;
  vector<item> items(n);
  rep(i, n) {
    int w, v;
    cin >> w >> v;
    items[i] = item(w, v);
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(1e5 + 1, inf));
  dp[0][0] = 0;
  rep(kind, n) {
    rep(value, 1e5 + 1) {
      item now_item = items[kind];
      chmin(dp[kind + 1][value], dp[kind][value]);
      int next_value = value + now_item.value;
      if(next_value > 1e5){
        continue;
      }
      chmin(dp[kind + 1][value + now_item.value],
            dp[kind][value] + now_item.weight);
    }
  }
  int ans = 0;
  rep(value,1e5+1){
    if(dp[n][value] <= W){
      chmax(ans,value);
    }
  }
  cout << ans << endl;
}