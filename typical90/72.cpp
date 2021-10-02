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
#include <stack>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int h, w, sx, sy;
vector<vector<char>> maze;
vector<vector<bool>> seen;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

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

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int dfs(int x, int y, int path)
{
    if (x == -1)
    {
        return 0;
    }
    if (x == h)
    {
        return 0;
    }
    if (y == -1)
    {
        return 0;
    }
    if (y == w)
    {
        return 0;
    }
    if (maze[x][y] == '#')
    {
        return 0;
    }
    if (seen[x][y])
    {
        if (x == sx && y == sy)
        {
            return path;
        }
        else
        {
            return 0;
        }
    }
    seen[x][y] = true;
    // debug(x);
    // debug(y);
    int ans = 0;
    rep(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        chmax<int>(ans, dfs(nx, ny, path + 1));
    }
    return ans;
}

int main(void)
{
    cin >> h >> w;
    seen = vector<vector<bool>>(h, vector<bool>(w, false));
    maze.resize(h);
    rep(i, h)
    {
        maze[i].resize(w);
        rep(j, w)
        {
            cin >> maze[i][j];
        }
    }
    print_maze(maze);
    int ans = -1;
    rep(i, h)
    {
        rep(j, w)
        {
            seen = vector<vector<bool>>(h, vector<bool>(w, false));
            sx = i;
            sy = j;
            int root = dfs(i, j, 0);
            debug(i);
            debug(j);
            debug(root);
            chmax<int>(ans, root);
        }
    }
    cout << ans << endl;
}