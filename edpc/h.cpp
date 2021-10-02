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

const ll mod = 1e9+7;

void print_maze(vector<vector<char>> maze) {
  int n = maze.size();
  int m = maze[0].size();
  rep(i, n) {
    rep(j, m) { cout << maze[i][j]; }
    cout << endl;
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> maze(h, vector<char>(w, '#'));
  rep(i, h) {
    rep(j, w) { cin >> maze[i][j]; }
  }
  // print_maze(maze);
  vector<vector<ll>> dp(h, vector<ll>(w, 0));
  dp[0][0] = 1;
  rep(now_h, h) {
    rep(now_w, w) {
      if (now_h + 1 < h && maze[now_h + 1][now_w] == '.') {
        dp[now_h + 1][now_w] += dp[now_h][now_w];
        dp[now_h + 1][now_w] %= mod;
      }
      if (now_w + 1 < w && maze[now_h][now_w + 1] == '.') {
        dp[now_h][now_w + 1] += dp[now_h][now_w];
        dp[now_h][now_w + 1] %= mod;
      }
    }
  }
  cout << dp[h-1][w-1] << endl;
}