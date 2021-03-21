#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
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

int h, w, a, b;

int dfs(vector<vector<bool>> maze, int now_h, int now_w, int now_a, int now_b) {
//   cout << "now ... " << now_h << " " << now_w << ", a & b is ... " << now_a
//        << " " << now_b << endl;
  int ans = 0;
  if (maze[now_h][now_w]) {
    if (now_h < h - 1) {
      return dfs(maze, now_h + 1, now_w, now_a, now_b);
    } else {
      return dfs(maze, 0, now_w + 1, now_a, now_b);
    }
  }
  if (now_h == 0 && now_w == w) {
    if (now_a == 0 && now_b == 0) {
    //   cout << "match!" << endl;
      return 1;
    }
  }
  if (now_a == -1 || now_b == -1) {
    return 0;
  }
  // hanjo
  vector<vector<bool>> maze_hanjo = maze;
  maze_hanjo[now_h][now_w] = true;
  if (now_h < h - 1) {
    ans += dfs(maze_hanjo, now_h + 1, now_w, now_a, now_b - 1);
  } else {
    ans += dfs(maze_hanjo, 0, now_w + 1, now_a, now_b - 1);
  }
  // vert
  vector<vector<bool>> maze_vert = maze;
  maze_vert[now_h][now_w] = true;
  maze_vert[now_h + 1][now_w] = true;
  if (now_h < h - 1) {
    ans += dfs(maze_vert, now_h + 1, now_w, now_a - 1, now_b);
  } else {
    ans += dfs(maze_vert, 0, now_w + 1, now_a - 1, now_b - 1);
  }
  // hori
  vector<vector<bool>> maze_hori = maze;
  maze_hori[now_h][now_w] = true;
  maze_hori[now_h][now_w + 1] = true;
  if (now_h < h - 1) {
    ans += dfs(maze_hori, now_h + 1, now_w, now_a - 1, now_b);
  } else {
    ans += dfs(maze_hori, 0, now_w + 1, now_a - 1, now_b);
  }
  return ans;
}

int main() {
  cin >> h >> w >> a >> b;
  vector<vector<bool>> maze(h + 1, vector<bool>(w + 1, false));
  cout << dfs(maze, 0, 0, a, b) << endl;
}