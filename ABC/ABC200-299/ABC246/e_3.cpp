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
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

int n;
vector<vector<char>> maze;
queue<pair<pair<int, int>, int>> q;
const int inf = 1e9;

vector<int> dx = {1, -1, 1, -1};
vector<int> dy = {1, 1, -1, -1};
vector<vector<vector<int>>> dist;

void dfs(int cx, int cy, int dir)
{
    rep(i, 4)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (nx < 0 || nx >= n)
        {
            continue;
        }
        if (ny < 0 || ny >= n)
        {
            continue;
        }
        if (maze[nx][ny] == '#')
        {
            continue;
        }
        if (dir == i)
        {
            int cost = dist[cx][cy][dir];
            if (dist[nx][ny][i] > cost)
            {
                dist[nx][ny][i] = cost;
                dfs(nx, ny, i);
            }
        }
        else
        {
            int cost = dist[cx][cy][dir] + 1;
            if (dist[nx][ny][i] > cost)
            {
                dist[nx][ny][i] = cost;
                q.push({{nx, ny}, i});
            }
        }
    }
    return;
}

int main(void)
{
    cin >> n;
    maze.resize(n, vector<char>(n));
    dist.resize(n, vector<vector<int>>(n, vector<int>(4, inf)));
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    ax--;
    ay--;
    bx--;
    by--;
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, n)
        {
            maze[i][j] = s[j];
        }
    }
    rep(i, 4)
    {
        dist[ax][ay][i] = 1;
        dfs(ax, ay, i);
    }
    while (q.size() > 0)
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        dfs(cx, cy, dir);
    }
    int ans = inf;
    rep(i, 4)
    {
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        chmin(ans, dist[bx][by][i]);
    }
    if (ans == inf)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}