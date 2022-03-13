#include <algorithm>
#include <iostream>
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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const ll inf = 1e18;

struct edge
{
  ll to, cost;
};
typedef pair<ll, ll> P;
struct graph
{
  ll V;
  vector<vector<edge>> G;
  vector<ll> d;

  graph(ll n)
  {
    init(n);
  }

  void init(ll n)
  {
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i, V)
    {
      d[i] = inf;
    }
  }

  void add_edge(ll s, ll t, ll cost)
  {
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s)
  {
    rep(i, V)
    {
      d[i] = inf;
    }
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (!que.empty())
    {
      P p = que.top();
      que.pop();
      ll v = p.second;
      if (d[v] < p.first)
        continue;
      for (auto e : G[v])
      {
        if (d[e.to] > d[v] + e.cost)
        {
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to], e.to));
        }
      }
    }
  }
};

int main(void)
{
  int n;
  cin >> n;
  graph g(n + 1);
  rep1(i, n)
  {
    ll s;
    cin >> s;
    int next = i + 1;
    if (i == n)
    {
      next = 1;
    }
    g.add_edge(i, next, s);
  }
  rep1(i, n)
  {
    ll t;
    cin >> t;
    g.add_edge(0, i, t);
  }
  g.dijkstra(0);
  rep1(i, n)
  {
    cout << g.d[i] << endl;
  }
}