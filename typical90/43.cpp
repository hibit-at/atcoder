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

const int inf = (int)1e9;

int main() {
  int h, w;
  cin >> h >> w;
  char maze[h + 2][w + 2];
  rep(i, h + 2) {
    rep(j, w + 2) { maze[i][j] = '#'; }
  }
  int hs, ws, ht, wt;
  cin >> hs >> ws >> ht >> wt;
  rep1(i, h) {
    rep1(j, w) { cin >> maze[i][j]; }
  }
  int dist[h + 2][w + 2][4];
  rep(i, h + 2) {
    rep(j, w + 2) {
      rep(k, 4) { dist[i][j][k] = inf; }
    }
  }
  int dh[] = {-1, 0, 1, 0};
  int dw[] = {0, 1, 0, -1};
  queue<pair<int, int>> q;
  q.push({hs, ws});
  rep(i, 4) { dist[hs][ws][i] = 0; }
  while (q.size() > 0) {
    int now_h = q.front().first;
    int now_w = q.front().second;
    q.pop();
    rep(i, 4) {
      int now_dist = dist[now_h][now_w][i];
      if (now_dist == inf) {
        continue;
      }
      rep(j, 4) {
        int next_h = now_h + dh[j];
        int next_w = now_w + dw[j];
        if (maze[next_h][next_w] == '#') {
          continue;
        }
        if (dist[next_h][next_w][j] <= now_dist + (i != j)) {
          continue;
        }
        dist[next_h][next_w][j] = now_dist + (i != j);
        q.push({next_h, next_w});
      }
    }
  }
  int ans = inf;
  rep(i, 4) { ans = min(ans, dist[ht][wt][i]); }
  cout << ans << endl;
}