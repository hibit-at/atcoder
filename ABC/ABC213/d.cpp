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

vector<vector<int>> to;
vector<bool> seen;

void dfs(int now) {
  seen[now] = true;
  cout << now << " ";
  for (int next : to[now]) {
    if (seen[next]) {
      continue;
    }
    // cout << "next target is" << next << endl;
    dfs(next);
    cout << now << " ";
  }
}

int main() {
  int n;
  cin >> n;
  to.resize(n + 1);
  seen.resize(n + 1);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep1(i, n) { sort(all(to[i])); }
  //   print_to(to);
  dfs(1);
}