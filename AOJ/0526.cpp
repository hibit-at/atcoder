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

const int inf = 1e9;

template <typename T>
vector<T> dijkstra(int n, vector<vector<pair<int, T>>> to, int start)
{
    vector<T> dist(n + 1, inf);
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (pq.size() > 0)
    {
        auto now_pair = pq.top();
        pq.pop();
        int now = now_pair.second;
        int now_dist = now_pair.first;
        if (dist[now] < now_dist)
        {
            continue;
        }
        for (auto next_pair : to[now])
        {
            int next = next_pair.first;
            T cost = next_pair.second;
            if (dist[now] + cost >= dist[next])
            {
                continue;
            }
            dist[next] = dist[now] + cost;
            pq.push({dist[next], next});
        }
    }
    return dist;
}

void solve(int n, int k)
{
    vector<vector<pair<int, int>>> to(n + 1, vector<pair<int, int>>());
    rep(i, k)
    {
        int q;
        cin >> q;
        if (q == 0)
        {
            int a, b;
            cin >> a >> b;
            vector<int> dist = dijkstra(n, to, a);
            if (dist[b] == inf)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << dist[b] << endl;
            }
        }
        if (q == 1)
        {
            int c, d, e;
            cin >> c >> d >> e;
            to[c].push_back({d, e});
            to[d].push_back({c, e});
        }
    }
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0)
    {
        return 0;
    }
    solve(n, k);
}