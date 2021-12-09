#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

struct UnionFind {
  vector<int> par;

  UnionFind(int N) : par(N) {
    for (int i = 0; i < N; i++)
      par[i] = i;
  }

  int root(int x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry)
      return;
    par[rx] = ry;
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int h, w;
  cin >> h >> w;
  int q;
  cin >> q;
  vector<int> dr = {1, -1, 0, 0};
  vector<int> dc = {0, 0, 1, -1};
  UnionFind un(h * w + 1);
  vector<vector<bool>> isRed(h, vector<bool>(w, false));
  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, c;
      cin >> r >> c;
      r--;
      c--;
      isRed[r][c] = true;
      rep(j, 4) {
        int nx = r + dr[j];
        int ny = c + dc[j];
        if (nx < 0 || nx >= h) {
          continue;
        }
        if (ny < 0 || ny >= w) {
          continue;
        }
        if (isRed[nx][ny]) {
          un.unite(r * w + c, nx * w + ny);
        }
      }
    } // if...t
    if (t == 2) {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;
      ca--;
      rb--;
      cb--;
      if (un.same(ra * w + ca, rb * w + cb) && isRed[ra][ca]) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } // if...t
  }   // i
}