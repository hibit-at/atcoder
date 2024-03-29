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

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

vector<int> dh = {0, 1};
vector<int> dw = {1, 0};

const int inf = 1e9;

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

int h, w;
vector<vector<char>> maze;
vector<vector<int>> dp;

int dfs(int now_h, int now_w, bool isTakahashi)
{
    if (now_h == h - 1 && now_w == w - 1)
    {
        return 0;
    }
    if (dp[now_h][now_w] > -inf)
    {
        return dp[now_h][now_w];
    }
    int init;
    if (isTakahashi)
    {
        init = -inf;
    }
    else
    {
        init = inf;
    }
    int ans = init;
    rep(i, 2)
    {
        int next_h = now_h + dh[i];
        int next_w = now_w + dw[i];
        if (next_h >= h)
        {
            continue;
        }
        if (next_w >= w)
        {
            continue;
        }
        int next_blue = (maze[next_h][next_w] == '+');
        int next_score = 2 * (isTakahashi == next_blue) - 1;
        if (isTakahashi)
        {
            chmax(ans, next_score + dfs(next_h, next_w, !isTakahashi));
        }
        else
        {
            chmin(ans, next_score + dfs(next_h, next_w, !isTakahashi));
        }
    }
    return dp[now_h][now_w] = ans;
}

int main(void)
{
    cin >> h >> w;
    maze.resize(h, vector<char>(w));
    dp.resize(h, vector<int>(w, -inf));
    dp[h - 1][w - 1] = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> maze[i][j];
        }
    }
    // print_vector_vector(maze);
    bool isTakahashi = true;
    int max_score = dfs(0, 0, isTakahashi);
    if (max_score > 0)
    {
        cout << "Takahashi" << endl;
    }
    else if (max_score == 0)
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << "Aoki" << endl;
    }
}