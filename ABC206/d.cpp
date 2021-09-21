#include <algorithm>
#include <iomanip>
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

struct UnionFind
{
  vector<int> par;

  UnionFind(int N) : par(N)
  {
    for (int i = 0; i < N; i++)
      par[i] = -1;
  }

  int root(int x)
  {
    if (par[x] < 0)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y)
  {
    int rx = root(x);
    int ry = root(y);
    if (same(x, y))
    {
      return;
    }
    if (par[rx] > par[ry])
      swap(rx, ry);
    par[rx] += par[ry];
    par[ry] = rx;
    return;
  }

  bool same(int x, int y)
  {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  int size(int x) { return -par[root(x)]; }
};

int main()
{
  int n;
  cin >> n;
  UnionFind uf(2e5 + 1);
  set<int> a_count;
  vector<int> a(n);
  rep(i, n)
  {
    cin >> a[i];
    a_count.insert(a[i]);
  }
  rep(i, n / 2)
  {
    uf.unite(a[i], a[n - 1 - i]);
  }
  set<int> r_count;
  rep(i, n)
  {
    r_count.insert(uf.root(a[i]));
  }
  cout << a_count.size() - r_count.size() << endl;
}