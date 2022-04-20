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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;
int h, w;
vector<vector<int>> maze;
vector<int> dh = {1, -1, 0, 0};
vector<int> dw = {0, 0, 1, -1};
vector<vector<int>> to;
vector<vector<int>> rev;
vector<int> graph;
vector<mint> dp;

int main(void)
{
    cin >> h >> w;
    int size = h * w;
    maze.resize(h, vector<int>(w, 0));
    to.resize(size, vector<int>(0));
    rev.resize(size, vector<int>(0));
    graph.resize(size, 0);
    dp.resize(size, 1);
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> maze[i][j];
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            rep(k, 4)
            {
                int nh = i + dh[k];
                int nw = j + dw[k];
                if (nh < 0 || nh >= h)
                {
                    continue;
                }
                if (nw < 0 || nw >= w)
                {
                    continue;
                }
                if (maze[i][j] < maze[nh][nw])
                {
                    to[i * w + j].push_back(nh * w + nw);
                    rev[nh * w + nw].push_back(i * w + j);
                    graph[i * w + j]++;
                }
            }
        }
    }
    stack<int> queue;
    rep(i, size)
    {
        if (graph[i] == 0)
        {
            queue.push(i);
        }
    }
    mint ans = 0;
    while (queue.size() > 0)
    {
        int now = queue.top();
        queue.pop();
        for (auto next : to[now])
        {
            dp[now] += dp[next];
        }
        ans += dp[now];
        for (auto from : rev[now])
        {
            graph[from]--;
            if (graph[from] == 0)
            {
                queue.push(from);
            }
        }
    }
    cout << ans.val() << endl;
}