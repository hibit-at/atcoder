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

int n, m, k, s;
ll p, q;
vector<bool> zombie;
vector<vector<int>> to;
vector<bool> danger;
vector<vector<pair<int, ll>>> edge;
const ll inf = 1e18;

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (int i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

void bfs(int start)
{
    vector<ll> dist(n + 1, inf);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        if (dist[now] <= s)
        {
            danger[now] = true;
        }
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

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        if (i < inf)
        {
            cout << i << ',';
        }
        else
        {
            cout << 'x' << ',';
        }
    }
    cout << endl;
    return;
}

template <typename T>
vector<T> dijkstra(vector<vector<pair<int, T>>> to, int start)
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
        // print_vector(dist);
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
    cin >> n >> m >> k >> s;
    cin >> p >> q;
    zombie.resize(n + 1);
    rep(i, k)
    {
        int c;
        cin >> c;
        zombie[c] = true;
    }
    to.resize(n + 1, vector<int>());
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    // print_vector_vector(to);
    danger.resize(n + 1);
    rep1(start, n)
    {
        if (zombie[start])
        {
            bfs(start);
        }
    }
    // print_vector(danger);
    edge.resize(n + 1, vector<pair<int, ll>>());
    rep1(start, n)
    {
        for (int end : to[start])
        {
            if (zombie[end])
            {
                continue;
            }
            if (end == n)
            {
                edge[start].push_back({end, 0});
                continue;
            }
            ll cost;
            if (danger[end])
            {
                cost = q;
            }
            else
            {
                cost = p;
            }
            edge[start].push_back({end, cost});
        }
    }
    vector<ll> dist = dijkstra(edge, 1);
    cout << dist[n] << endl;
}