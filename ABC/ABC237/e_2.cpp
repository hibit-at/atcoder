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

void print_to_with_cost(vector<vector<pair<int, ll>>> to)
{
    int n = to.size();
    rep(i, n)
    {
        cout << "from " << i << " : ";
        for (auto p : to[i])
        {
            cout << "(to " << p.first << ",cost " << p.second << ") ";
        }
        cout << endl;
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
void print_to(vector<vector<T>> to)
{
    int n = to.size();
    rep(i, n)
    {
        cout << "from " << i << " : to ";
        for (int next : to[i])
        {
            cout << next << ",";
        }
        cout << endl;
    }
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

vector<ll> h;

ll cost(int from, int next)
{
    if (h[from] > h[next])
    {
        return -(h[from] - h[next]);
    }
    else
    {
        return -2 * (h[from] - h[next]);
    }
}

const ll inf = 1e18;

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
            int cost = next_pair.second;
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
    int n, m;
    vector<vector<pair<int, ll>>> to;
    cin >> n >> m;
    h.resize(n + 1);
    rep1(i, n)
    {
        cin >> h[i];
    }
    to.resize(n + 1);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back({v, abs(h[u] - h[v])});
        to[v].push_back({u, abs(h[u] - h[v])});
    }
    // print_to_with_cost(to);
    vector<ll> dist = dijkstra(n, to, 1);
    // print_vector(dist);
    ll ans = 0;
    rep1(i, n)
    {
        chmax(ans, -(dist[i] + 3 * (h[i] - h[1])) / 2);
    }
    cout << ans << endl;
    // cout << -(*min_element(all(dist))) << endl;
}