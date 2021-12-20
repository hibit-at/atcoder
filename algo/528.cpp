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

const int inf = 1e9;

vector<int> bfs(int n, vector<vector<int>> to, int start)
{
    vector<int> dist(n + 1, inf);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
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
    return dist;
}

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> to(n, vector<int>());
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> dist = bfs(n, to, x);
    int ans = 0;
    for (int i : dist)
    {
        if (i == 2)
        {
            ans++;
        }
    }
    cout << ans << endl;
}