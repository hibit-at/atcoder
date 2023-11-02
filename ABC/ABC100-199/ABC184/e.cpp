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

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> maze(h, vector<char>(w));
    map<char, vector<pair<int, int>>> warp;
    int sh, sw, gh, gw;
    rep(i, h)
    {
        rep(j, w)
        {
            char c;
            cin >> c;
            if (c == 'S')
            {
                sh = i;
                sw = j;
                maze[i][j] = c;
            }
            else if (c == 'G')
            {
                gh = i;
                gw = j;
                maze[i][j] = c;
            }
            else if (c == '#')
            {
                maze[i][j] = c;
            }
            else if (c != '.')
            {
                warp[c].push_back({i, j});
                maze[i][j] = c;
            }
            else
            {
                maze[i][j] = c;
            }
        }
    }
    auto print_maze = [](auto maze)
    {
        int n = maze.size();
        int m = maze[0].size();
        rep(i, n)
        {
            rep(j, m) { cout << maze[i][j]; }
            cout << endl;
        }
    };
    // print_maze(maze);
    queue<pair<int, int>> q;
    vector<int> dh = {1, -1, 0, 0};
    vector<int> dw = {0, 0, 1, -1};
    q.push({sh, sw});
    map<char, bool> seen;
    const int inf = 2e9;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[sh][sw] = 0;
    while (q.size() > 0)
    {
        int ch = q.front().first;
        int cw = q.front().second;
        q.pop();
        rep(i, 4)
        {
            int nh = ch + dh[i];
            int nw = cw + dw[i];
            if (nh < 0 || h <= nh)
            {
                continue;
            }
            if (nw < 0 || w <= nw)
            {
                continue;
            }
            if (maze[nh][nw] == '#')
            {
                continue;
            }
            if (dist[nh][nw] <= dist[ch][cw] + 1)
            {
                continue;
            }
            dist[nh][nw] = dist[ch][cw] + 1;
            q.push({nh, nw});
        }
        char cc = maze[ch][cw];
        if (cc == '.')
        {
            continue;
        }
        if (seen[cc])
        {
            continue;
        }
        for (auto next : warp[cc])
        {
            int nh = next.first;
            int nw = next.second;
            if (dist[nh][nw] <= dist[ch][cw] + 1)
            {
                continue;
            }
            dist[nh][nw] = dist[ch][cw] + 1;
            q.push({nh, nw});
        }
        seen[cc] = true;
    }
    int ans = dist[gh][gw];
    if (ans == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}