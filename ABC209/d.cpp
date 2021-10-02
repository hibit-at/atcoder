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

const ll mod = 1e9 + 7;
const int inf = 2e5;

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

int main() {
  int n, query;
  cin >> n >> query;
  vector<vector<int>> to(n + 1, vector<int>(0));
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int> dist(n + 1, inf);
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    for (int next : to[now]) {
      if (dist[now] + 1 < dist[next]) {
        dist[next] = dist[now] + 1;
        q.push(next);
      }
    }
  }
  // print_vector(dist);
  rep(i, query) {
    int c, d;
    cin >> c >> d;
    int dif = dist[c] - dist[d];
    if (dif % 2 == 0) {
      cout << "Town" << endl;
    } else {
      cout << "Road" << endl;
    }
  }
}