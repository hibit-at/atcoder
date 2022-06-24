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

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

struct Edge
{
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;
void dijkstra(const Graph &G, int s, vector<long long> &dis, int k)
{
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq; // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first)
        { // 最短距離で無ければ無視
            continue;
        }
        if (dis[v] >= k)
        {
            continue;
        }
        for (auto &e : G[v])
        {
            if (dis[e.to] > dis[v] + e.cost)
            { // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    Graph graph(n, vector<Edge>(0));
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        x--;
        vector<ll> dist;
        dijkstra(graph, x, dist, k);
        auto print_vector = [](auto v)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        };
        // print_vector(dist);
        ll ans = 0;
        rep(i, n)
        {
            ans += (i+1) * (dist[i] <= k);
        }
        cout << ans << endl;
    }
}