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

#include <fstream>

int main(void)
{
    // ifstream in("max_01.txt");
    // cin.rdbuf(in.rdbuf());
    int h, w;
    cin >> h >> w;
    int Ch, Cw, sh, sw;
    cin >> Ch >> Cw >> sh >> sw;
    Ch--;
    Cw--;
    sh--;
    sw--;
    vector<vector<char>> maze(h, vector<char>(w));
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> maze[i][j];
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
    deque<pair<int, int>> q;
    q.push_back({Ch, Cw});
    const int inf = 1e9;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[Ch][Cw] = 0;
    vector<int> dh = {1, -1, 0, 0};
    vector<int> dw = {0, 0, 1, -1};
    while (q.size() > 0)
    {
        int ch = q.front().first;
        int cw = q.front().second;
        int cd = dist[ch][cw];
        q.pop_front();
        rep(i, 4)
        {
            int nh = ch + dh[i];
            int nw = cw + dw[i];
            if (nh < 0 || nh >= h)
            {
                continue;
            }
            if (nw < 0 || nw >= w)
            {
                continue;
            }
            if (maze[nh][nw] == '#')
            {
                continue;
            }
            if (dist[nh][nw] <= cd)
            {
                continue;
            }
            dist[nh][nw] = cd;
            q.push_front({nh, nw});
        }
        rep(i, 5)
        {
            rep(j, 5)
            {
                int nh = ch + i - 2;
                int nw = cw + j - 2;
                if (nh < 0 || nh >= h)
                {
                    continue;
                }
                if (nw < 0 || nw >= w)
                {
                    continue;
                }
                if (maze[nh][nw] == '#')
                {
                    continue;
                }
                if (dist[nh][nw] <= cd + 1)
                {
                    continue;
                }
                dist[nh][nw] = cd + 1;
                q.push_back({nh, nw});
            }
        }
    }
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        }
    };
    // print_vector_vector(dist);
    int ans = dist[sh][sw];
    if (ans == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}