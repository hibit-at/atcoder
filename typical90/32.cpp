#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

const int inf = 1e6;

void chmin(int &a, int b) { a = min(a, b); }

void print_vector_vector(vector<vector<int>> vv) {
  for (vector<int> v : vv) {
    for (int i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

void tobit(int n, int d) {
  rep(i, d) {
    bool bit = (n >> i) & 1;
    cout << bit;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));
  rep(i, n) {
    rep(j, n) { cin >> a[i][j]; }
  }
  int m;
  cin >> m;
  // vector<vector<bool>> isHate(n, vector<bool>(n, false));
  vector<bool> isHate(1 << n, false);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    isHate[(1 << x) | (1 << y)] = true;
  }
  vector<vector<int>> dp(1 << n, vector<int>(n, inf));
  rep(i, n) {
    int next_pos = i;
    int next_state = 1 << next_pos;
    dp[next_state][next_pos] = a[next_pos][0];
  }
  rep(i, (1 << n) - 1) {
    int now_state = i;
    rep(j, n) {
      int now_pos = j;
      bool check = (now_state >> j) & 1;
      if (!check) {
        continue;
      }
      rep(k, n) {
        int next_pos = k;
        if (next_pos == now_pos) {
          continue;
        }
        bool check = (now_state >> next_pos) & 1;
        if (check) {
          continue;
        }
        if (isHate[(1 << next_pos) | (1 << now_pos)]) {
          continue;
        }
        int next_state = (1 << next_pos) | now_state;
        int step = __builtin_popcount(now_state);
        chmin(dp[next_state][next_pos],
              dp[now_state][now_pos] + a[next_pos][step]);
      }
    }
  }
  int ans = *min_element(all(dp[(1 << n) - 1]));
  if (ans == inf) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}