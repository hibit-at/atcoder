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

ll mod = (ll)1e9 + 7;

vector<int> graph;
vector<vector<int>> to;
vector<bool> seen;


int main() {
  int n, m;
  cin >> n >> m;

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep(i, n) {
    if (seen[i])
      continue;
    queue<int> q;
    q.push(i);
  }
}