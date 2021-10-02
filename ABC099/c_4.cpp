#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

const ll mod = (ll)1e9 + 7;
const int inf = 2e5;

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

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

vector<int> bfs(int n, vector<vector<int>> to, int start) {
  vector<int> dist(n + 1, inf);
  queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    for (int next : to[now]) {
      if (dist[next] <= dist[now] + 1) {
        continue;
      }
      dist[next] = dist[now] + 1;
      q.push(next);
    }
  }
  return dist;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> to(n + 1, vector<int>(0));
  rep(i, n + 1) {
    int step = 1;
    while (i + step <= n) {
      to[i].push_back(i + step);
      step *= 6;
    }
    step = 9;
    while (i + step <= n) {
      to[i].push_back(i + step);
      step *= 9;
    }
  }
  vector<int> dist = bfs(n, to, 0);
  cout << dist[n] << endl;
}