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

int n, m;
vector<ll> h;
vector<vector<pair<int, ll>>> to;

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

int main(void)
{
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
        to[u].push_back({v, cost(u, v)});
        to[v].push_back({u, cost(v, u)});
    }
    // print_to_with_cost(to);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n + 1, inf);
    dist[1] = 0;
    pq.push({0, 1});
    while (pq.size() > 0)
    {
        auto now_pair = pq.top();
        pq.pop();
        int now = now_pair.second;
        // debug(now);
        ll now_dist = now_pair.first;
        if (dist[now] < now_dist)
        {
            continue;
        }
        for (auto next_pair : to[now])
        {
            int next = next_pair.first;
            ll cost = next_pair.second;
            if (dist[now] + cost >= dist[next])
            {
                continue;
            }
            dist[next] = dist[now] + cost;
            pq.push({dist[next], next});
        }
    }
    // print_vector(dist);
    cout << -(*min_element(all(dist))) << endl;
}