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
vector<pair<int, int>> path;
priority_queue<int> ans;
int dh[] = {1, -1, 0, 0};
int dw[] = {0, 0, 1, -1};

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

void dfs(int now_h, int now_w)
{
    seen[now_h][now_w] = true;
    path.push_back({now_h, now_w});
    rep(i, 4)
    {
        int next_h = now_h + dh[i];
        int next_w = now_w + dw[i];
        if (next_h < 0 || next_h >= h)
        {
            continue;
        }
        if (next_w < 0 || next_w >= w)
        {
            continue;
        }
        if (maze[next_h][next_w] == '#')
        {
            continue;
        }
        if (seen[next_h][next_w])
        {
            pair<int, int> next = {next_h, next_w};
            if (next == path.front() && path.size() > 2)
            {
                ans.push(path.size());
            }
            continue;
        }
        dfs(next_h, next_w);
    }
    path.pop_back();
    seen[now_h][now_w] = false;
    return;
}

int main()
{
    cin >> h >> w;
    maze.resize(h);
    rep(i, h)
    {
        maze[i].resize(w);
        rep(j, w)
        {
            cin >> maze[i][j];
        }
    }
    seen.resize(h);
    rep(i, h)
    {
        seen[i].resize(w);
    }
    rep(i, h)
    {
        rep(j, w)
        {
            dfs(i, j);
        }
    }
    if (ans.size())
    {
        cout << ans.top() << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}