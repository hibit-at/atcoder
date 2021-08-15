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

vector<bool> seen;
vector<bool> opt;
vector<vector<pair<int, int>>> to;

void print_to_with_cost(vector<vector<pair<int, int>>> to) {
  int n = to.size();
  rep(i, n) {
    cout << "from " << i << " : ";
    for (auto p : to[i]) {
      cout << "(to " << p.first << ",cost " << p.second << ") ";
    }
    cout << endl;
  }
}

ll dfs(int now) {
  ll ans = 0;
  cout << now << endl;
  seen[now] = true;
  for (auto next_pair : to[now]) {
    int next = next_pair.first;
    if (seen[next]) {
      continue;
    }
    cout << "next target is " << next << endl;
    if (opt[now] and opt[next]) {
      continue;
    }
    ans += 1 + dfs(next);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  opt.resize(n + 1, false);
  to.resize(n + 1);
  rep1(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    seen = vector<bool>(n + 1, false);
    seen[u] = true;
    seen[v] = true;
    cout << dfs(u) << endl;
    cout << dfs(v) << endl;
  }
}