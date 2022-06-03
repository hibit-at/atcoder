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

struct Edge
{
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;

void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev)
{
    int N = G.size();
    dis.resize(N, INF);
    prev.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first)
        {
            continue;
        }
        for (auto &e : G[v])
        {
            if (dis[e.to] > dis[v] + e.cost)
            {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

vector<int> get_path(const vector<int> &prev, int t)
{
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur])
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    Graph graph(n, vector<Edge>(0));
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[b].push_back(Edge({a, c}));
        graph[a].push_back(Edge({b, c}));
    }
    vector<ll> dist;
    vector<int> prev;
    dijkstra(graph, 0, dist, prev);
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    print_vector(dist);
    print_vector(prev);
    vector<int> way_back(1,n-1);
    int pos = n-1;
    while(prev[pos] > -1){
        pos = prev[pos];
        way_back.push_back(pos);
    }
    reverse(all(way_back));
    print_vector(way_back);
    
}