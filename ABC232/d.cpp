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

int h, w;
vector<vector<char>> maze;
vector<vector<int>> memo;

int dfs(int now_h, int now_w)
{
    if (now_h >= h)
    {
        return 0;
    }
    if (now_w >= w)
    {
        return 0;
    }
    if (maze[now_h][now_w] == '#')
    {
        return 0;
    }
    if (memo[now_h][now_w] > -1)
    {
        return memo[now_h][now_w];
    }
    // cout << now_h << ',' << now_w << endl;
    int ans = max(dfs(now_h + 1, now_w), dfs(now_h, now_w + 1));
    return memo[now_h][now_w] = 1 + ans;
}

int main(void)
{
    cin >> h >> w;
    maze.resize(h);
    memo.resize(h);
    rep(i, h)
    {
        maze[i].resize(w);
        memo[i].resize(w, -1);
    }
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> maze[i][j];
        }
    }
    // print_maze(maze);
    cout << dfs(0, 0) << endl;
}