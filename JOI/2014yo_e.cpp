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

int n, k;
vector<int> c, r;
vector<vector<pair<int, int>>> to;

void bfs(int n, vector<vector<int>> to_bfs, int start)
{
    vector<int> dist(n + 1, inf);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        for (int next : to_bfs[now])
        {
            if (dist[next] <= dist[now] + 1)
            {
                continue;
            }
            dist[next] = dist[now] + 1;
            if (dist[next] <= r[start])
            {
                to[start].push_back({next, c[start]});
            }
            q.push(next);
        }
    }
}

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

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

int main(void)
{
    cin >> n >> k;
    c.resize(n + 1);
    r.resize(k + 1);
    rep1(i, n)
    {
        cin >> c[i] >> r[i];
    }
    vector<vector<int>> to_bfs(n + 1);
    rep(i, k)
    {
        int a, b;
        cin >> a >> b;
        to_bfs[a].push_back(b);
        to_bfs[b].push_back(a);
    }
    to.resize(n + 1, vector<pair<int, int>>());
    rep1(start, n)
    {
        bfs(n, to_bfs, start);
    }
    vector<int> dist = dijkstra(n, to, 1);
    cout << dist[n] << endl;
}