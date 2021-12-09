#include <algorithm>
#include <iostream>
#include <iomanip>
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
#include <stack>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

vector<vector<int>> to;
const int inf = 1e9;
int ans = 0;

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

void print_maze(vector<vector<char>> maze)
{
  int n = maze.size();
  int m = maze[0].size();
  rep(i, n)
  {
    rep(j, m) { cout << maze[i][j]; }
    cout << endl;
  }
}
int main()
{
  int h, w;
  cin >> h >> w;
  int sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  vector<vector<char>> maze(h, vector<char>(w, 'W'));
  rep(i, h)
  {
    string s;
    cin >> s;
    int n = s.size();
    rep(j, n)
    {
      maze[i][j] = s[j];
    }
  }
  // print_maze(maze);
  queue<pair<int, int>> q;
  q.push({sx, sy});
  vector<vector<int>> dist(h, vector<int>(w, inf));
  dist[sx][sy] = 0;
  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};
  while (q.size() > 0)
  {
    auto now = q.front();
    q.pop();
    int now_x = now.first;
    int now_y = now.second;
    rep(i, 4)
    {
      int next_x = now_x + dx[i];
      if (next_x < 0 || next_x >= h)
      {
        continue;
      }
      int next_y = now_y + dy[i];
      if (next_y < 0 || next_y >= w)
      {
        continue;
      }
      if (dist[next_x][next_y] <= dist[now_x][now_y] + 1)
      {
        continue;
      }
      if (maze[next_x][next_y] == 'B')
      {
        continue;
      }
      dist[next_x][next_y] = dist[now_x][now_y] + 1;
      q.push({next_x, next_y});
    }
  }
  cout << dist[ex][ey] << endl;
}