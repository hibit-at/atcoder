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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

vector<vector<int>> to;
const int inf = 1e9;

vector<int> bfs(int n, vector<vector<int>> to, int start)
{
  vector<int> dist(n, inf);
  queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (q.size() > 0)
  {
    int now = q.front();
    q.pop();
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
  return dist;
}

template <typename T>
void print_vector(vector<T> v)
{
  for (T i : v)
  {
    cout << i << ",";
  }
  cout << endl;
  return;
}

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

int main()
{
  int n, m;
  cin >> n >> m;
  to.resize(n);
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int> cost = bfs(n, to, 0);
  // print_vector(cost);
  vector<vector<int>> vv(n);
  rep(i, n)
  {
    if (cost[i] == inf)
    {
      continue;
    }
    vv[cost[i]].push_back(i);
  }
  // print_vector_vector(vv);
  rep(i, n)
  {
    if (vv[i].size() == 0)
    {
      return 0;
    }
    for (int v : vv[i])
    {
      cout << v << ' ';
    }
    cout << endl;
  }
}