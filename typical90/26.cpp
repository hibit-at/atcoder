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

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void print_vector_vector(vector<vector<int>> vv) {
  for (vector<int> v : vv) {
    for (int i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> graph(n + 1, -1);
  vector<vector<int>> to(n + 1, vector<int>(0));
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep1(i, n) {
    if (graph[i] != -1) {
      continue;
    }
    queue<int> q;
    q.push(i);
    graph[i] = 0;
    while (q.size() > 0) {
      int now = q.front();
      q.pop();
      for (int next : to[now]) {
        if (graph[next] != -1) {
          continue;
        }
        graph[next] = 1 - graph[now];
        q.push(next);
      }
    }
  }
  vector<vector<int>> odd_or_even(2, vector<int>(0));
  rep1(i, n) { odd_or_even[graph[i]].push_back(i); }
  // print_vector_vector(odd_or_even);
  if (odd_or_even[0].size() >= n / 2) {
    rep(i, n / 2) { cout << odd_or_even[0][i] << ' '; }
  } else {
    rep(i, n / 2) { cout << odd_or_even[1][i] << ' '; }
  }
}