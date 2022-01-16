#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void chmin(int &a, int b) { a = min(a, b); }

int main() {
  int n;
  cin >> n;
  vector<vector<int>> to(n + 1, vector<int>(0));
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  queue<int> q;
  vector<int> dist(n + 1, 1e9);
  q.push(1);
  dist[1] = 0;
  int temporal_max = 0;
  int where_max = 0;
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    if (dist[now] > temporal_max) {
      temporal_max = dist[now];
      where_max = now;
    }
    for (int next : to[now]) {
      if (dist[now] + 1 < dist[next]) {
        dist[next] = dist[now] + 1;
        q.push(next);
      }
    }
  }
  // print_vector(dist);
  // cout << temporal_max << "," << where_max << endl;
  vector<int> new_dist(n + 1, 1e9);
  new_dist[where_max] = 0;
  q.push(where_max);
  int ans = 0;
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    if (new_dist[now] > ans) {
      ans = new_dist[now];
    }
    for (int next : to[now]) {
      if (new_dist[now] + 1 < new_dist[next]) {
        new_dist[next] = new_dist[now] + 1;
        q.push(next);
      }
    }
  }
  // print_vector(new_dist);
  cout << ans + 1 << endl;
}