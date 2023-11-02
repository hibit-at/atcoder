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
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n + 1);
    rep1(i, n)
    {
        cin >> a[i];
    }
    vector<vector<pair<int, ll>>> to(n + 1, vector<pair<int, ll>>());
    vector<vector<pair<int, ll>>> back(n + 1, vector<pair<int, ll>>());
    rep(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        to[a].push_back({b, c});
        back[b].push_back({a, c});
    }
    ll ans = 0;
    vector<ll> dist = dijkstra(n, to, 1);
    vector<ll> dist_back = dijkstra(n, back, 1);
    // print_vector(dist);
    // print_vector(dist_back);
    rep1(i, n)
    {
        ll go_back = dist[i] + dist_back[i];
        if (go_back > t)
        {
            continue;
        }
        chmax(ans, a[i] * (t - go_back));
    }
    cout << ans << endl;
}