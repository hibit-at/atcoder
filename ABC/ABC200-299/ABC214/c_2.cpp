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
using mint = modint;

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

int main(void)
{
    int n;
    cin >> n;
    vector<ll> s(n), t(n);
    vector<vector<pair<int, ll>>> to(n + 1, vector<pair<int, ll>>());
    mint::set_mod(n);
    rep(i, n)
    {
        ll s;
        cin >> s;
        mint pos = i;
        to[pos.val()].push_back({(pos + 1).val(), s});
    }
    rep(i, n)
    {
        ll t;
        cin >> t;
        to[n].push_back({i, t});
    }
    vector<ll> dist = dijkstra(n, to, n);
    rep(i, n)
    {
        cout << dist[i] << endl;
    }
}