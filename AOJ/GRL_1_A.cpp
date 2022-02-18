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
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<pair<int, int>>> to(v, vector<pair<int, int>>());
    rep(i, e)
    {
        int s, t, d;
        cin >> s >> t >> d;
        to[s].push_back({t, d});
    }
    vector<int> dist = dijkstra(v, to, r);
    rep(i, v)
    {
        if (dist[i] < inf)
        {
            cout << dist[i] << endl;
        }
        else
        {
            cout << "INF" << endl;
        }
    }
}