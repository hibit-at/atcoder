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

const int inf = 2e5;

int n, m;
vector<vector<int>> to;
vector<int> dp;

void chmax(int &a, int b) { a = max(a, b); }

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
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

int dfs(int now) {
  if (now < 1) {
    return -1;
  }
  if (dp[now] > -1) {
    return dp[now];
  }
  //   cout << "now " << now << endl;
  if (to[now].size() > 0) {
    int ans = 0;
    for (int next : to[now]) {
      chmax(ans, 1 + dfs(next));
    }
    return dp[now] = ans;
  } else {
    return dp[now] = 0;
  }
}

int main() {
  cin >> n >> m;
  to.resize(n + 1);
  dp.resize(n + 1, -1);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    to[x].push_back(y);
  }
  //   print_to(to);
  int ans = -1;
  rep1(i, n) { chmax(ans, dfs(i)); }
  //   print_vector(dp);
  cout << ans << endl;
}