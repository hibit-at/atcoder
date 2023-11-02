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

#include <atcoder/dsu>
using namespace atcoder;

struct Edge
{
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;
void dijkstra(const Graph &G, int s, vector<long long> &dis)
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
    int n;
    cin >> n;
    vector<ll> x(n), y(n), p(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i] >> p[i];
    }
    ll ng = 0;
    ll ok = 1e9 + 1;
    while (abs(ng - ok) > 1)
    {
        ll mid = ng + ok;
        mid /= 2;
        auto solve = [&]()
        {
            Graph graph(n, vector<Edge>());
            rep(i, n)
            {
                rep(j, n)
                {
                    ll jump = p[i] * mid;
                    ll man = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                    if (jump >= man)
                    {
                        graph[i].push_back({j, 1});
                    }
                }
            }
            rep(i, n)
            {
                vector<ll> dist;
                dijkstra(graph, i, dist);
                auto print_vector = [](auto v)
                {
                    for (auto i : v)
                    {
                        cout << i << ',';
                    }
                    cout << endl;
                };
                // print_vector(dist);
                if (*max_element(all(dist)) < INF)
                {
                    return true;
                }
            }
            return false;
        };
        if (solve())
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}