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

int main(void)
{
    cin >> n;
    maze.resize(n, vector<char>(n));
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
    queue<pair<int, pair<int, int>>> q;
    vector<int> dx = {1, -1, 1, -1};
    vector<int> dy = {1, 1, -1, -1};
    const int inf = 1e9;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, inf)));
    rep(i, 4)
    {
        dist[ax][ay][i] = 1;
        q.push({i, {ax, ay}});
    }
    while (q.size() > 0)
    {
        int type = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
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
            if (type == i)
            {
                int cost = dist[cx][cy][type];
                if (cost < dist[nx][ny][i])
                {
                    dist[nx][ny][i] = cost;
                    q.push({i, {nx, ny}});
                }
            }
            else
            {
                int cost = dist[cx][cy][type] + 1;
                if (cost < dist[nx][ny][i])
                {
                    dist[nx][ny][i] = cost;
                    q.push({i, {nx, ny}});
                }
            }
        }
    }
    int ans = *min_element(all(dist[bx][by]));
    if (ans == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}