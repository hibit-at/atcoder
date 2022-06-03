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

bool isAlpha(char c)
{
    return ('a' <= c && c <= 'z');
}

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> maze(h + 26, vector<char>(w));
    map<pair<int, int>, vector<pair<int, int>>> to;
    int sh, sw, gh, gw;
    deque<pair<int, int>> q;
    int inf = 2e9;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    rep(i, h)
    {
        rep(j, w)
        {
            char cc;
            cin >> cc;
            maze[i][j] = cc;
            if (cc == 'S')
            {
                q.push_back({i, j});
                dist[i][j] = 0;
            }
            else if (cc == 'G')
            {
                gh = i;
                gw = j;
            }
            else if (isalpha(cc))
            {
                int warp = h + cc - 'a';
                to[{i, j}].push_back({warp, 0});
                to[{warp, 0}].push_back({i, j});
            }
        }
    }
    vector<int> dh = {1, -1, 0, 0};
    vector<int> dw = {0, 0, 1, -1};
    while (q.size() > 0)
    {
        int ch = q.front().first;
        int cw = q.front().second;
        char cc = maze[ch][cw];
        q.pop_front();
        if (ch == gh && cw == gw)
        {
            cout << dist[ch][cw] << endl;
            return 0;
        }
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
            q.push_back({nh, nw});
        }
        for (pair<int, int> next_pair : to[{ch, cw}])
        {
            // debug(ch);
            // debug(cw);
            // debug(cc);
            int nh = next_pair.first;
            int nw = next_pair.second;
            // debug(nh);
            // debug(nw);
            if (dist[nh][nw] <= dist[ch][cw] + 1)
            {
                continue;
            }
            dist[nh][nw] = dist[ch][cw];
        }
    }
}