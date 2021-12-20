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

const int inf = 2e9;

ll cnt = 0;
int n, m;
vector<vector<int>> to;
vector<vector<int>> rev;
vector<bool> seen;
vector<int> order;

void print_vector_vector(vector<vector<int>> vv) {
  for (vector<int> v : vv) {
    for (int i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void print_vector_pair(vector<pair<int, int>> v) {
  for (pair<int, int> i : v) {
    cout << "(" << i.first << "," << i.second << ")"
         << " ";
  }
  cout << endl;
}

void dfs1(int now) {
  seen[now] = true;
  for (int next : to[now]) {
    if (seen[next]) {
      continue;
    }
    dfs1(next);
  }
  order.push_back(now);
}

void dfs2(int now) {
  seen[now] = true;
  cnt++;
  for (int next : rev[now]) {
    if (seen[next]) {
      continue;
    }
    dfs2(next);
  }
}

int main() {
  cin >> n >> m;
  to.resize(n + 1);
  rev.resize(n + 1);
  seen.resize(n + 1, false);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    rev[b].push_back(a);
  }
  rep1(i, n) {
    if (seen[i]) {
      continue;
    }
    dfs1(i);
  }
  // print_vector(order);
  reverse(all(order));
  // print_vector(order);
  rep1(i, n) { seen[i] = false; }
  ll ans = 0;
  rep(i, n) {
    int start = order[i];
    if (seen[start]) {
      continue;
    }
    cnt = 0;
    dfs2(start);
    ans += cnt * (cnt - 1) / 2;
  }
  cout << ans << endl;
}