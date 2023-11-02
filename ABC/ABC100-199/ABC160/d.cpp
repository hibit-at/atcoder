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
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<vector<int>> to(n);
    rep(i, n - 1)
    {
        to[i].push_back(i + 1);
        to[i + 1].push_back(i);
    }
    to[x].push_back(y);
    to[y].push_back(x);
    vector<int> ans(n);
    rep(start, n)
    {
        int inf = 1e9;
        vector<int> dist(n, inf);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while (q.size() > 0)
        {
            int now = q.front();
            q.pop();
            int now_dist = dist[now];
            ans[now_dist]++;
            for (int next : to[now])
            {
                if (dist[next] <= dist[now] + 1)
                {
                    continue;
                }
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    auto print_lines = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << endl;
        }
    };
    rep(i, n)
    {
        if (i == 0)
        {
            continue;
        }
        cout << ans[i] / 2 << endl;
    }
}