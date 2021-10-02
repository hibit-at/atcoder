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

struct UnionFind {
  vector<int> par;

  UnionFind(int N) : par(N) {
    for (int i = 0; i < N; i++)
      par[i] = -1;
  }

  int root(int x) {
    if (par[x] < 0)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (same(x, y)) {
      return;
    }
    if (par[rx] > par[ry])
      swap(rx, ry);
    par[rx] += par[ry];
    par[ry] = rx;
    return;
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  int n;
  cin >> n;
  UnionFind uf(n + 1);
  vector<tuple<int,int,int>> to;
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    to.push_back({w,u,v});
  }
  sort(all(to));
  ll ans = 0;
  for (auto t : to) {
    int u,v,w;
    tie(w,u,v) = t;
    ans += 1LL * w * uf.size(u) * uf.size(v);
    uf.unite(u, v);
  }
  cout << ans << endl;
}