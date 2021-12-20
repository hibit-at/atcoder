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

vector<int> bfs_with_cost(int n, vector<vector<pair<int, int>>> to, int start) {
  vector<int> dist(n + 1, inf);
  queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    for (auto next_pair : to[now]) {
      int next = next_pair.first;
      int cost = next_pair.second;
      if (dist[next] <= dist[now] + cost) {
        continue;
      }
      dist[next] = dist[now] + cost;
      q.push(next);
    }
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> to(n + 1, vector<pair<int, int>>(0));
  rep(i, m) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    to[a].push_back({b, c});
    to[b].push_back({a, c});
  }
  vector<int> dist_start = bfs_with_cost(n, to, 1);
  vector<int> dist_end = bfs_with_cost(n, to, n);
  rep1(i, n) { cout << dist_start[i] + dist_end[i] << endl; }
}