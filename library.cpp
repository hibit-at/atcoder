#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

ll const mod = (ll)1e9 + 7;
ll const inf = (ll)2e9;

int inf_to_minus(int n) {
  if (n == inf) {
    return -1;
  }
  return n;
}

char inf_to_wall(int n) {
  if (n == inf) {
    return '#';
  }
  return n + '0';
}

void chmax(int &a, int b) { a = max(a, b); }

void chmin(int &a, int b) { a = min(a, b); }

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int index(vector<int> v, int target) {
  return find(all(v), target) - v.begin();
}

void plus_mod(ll &a, ll b, ll mod) {
  a += b;
  a %= mod;
}

void sub_mod(int &a, int b, int mod) {
  a -= b;
  a %= mod;
  a += mod;
  a %= mod;
}

vector<int> bfs_with_cost(int n, vector<vector<pair<int, int>>> to, int start) {
  vector<int> dist(n + 1, inf);
  queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    for (auto next_pair : to[now]) {
      int next = next_pair.first;
      int cost = next_pair.second;
      if (dist[next] <= dist[now] + cost) {
        continue;
      }
      dist[next] = dist[now] + cost;
      q.push(next);
    }
  }
  return dist;
}

vector<int> bfs(int n, vector<vector<int>> to, int start) {
  vector<int> dist(n + 1, inf);
  queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    for (int next : to[now]) {
      if (dist[next] <= dist[now] + 1) {
        continue;
      }
      dist[next] = dist[now] + 1;
      q.push(next);
    }
  }
  return dist;
}

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> ans;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ll ex = 0;
      while (n % i == 0) {
        ex++;
        n /= i;
      }
      ans.push_back({i, ex});
    }
  }
  if (n != 1) {
    ans.push_back({n, 1});
  }
  return ans;
}

struct UnionFind {
  vector<int> par;

  UnionFind(int N) : par(N) {
    for (int i = 0; i < N; i++)
      par[i] = i;
  }

  int root(int x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry)
      return;
    par[rx] = ry;
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

void print_to_with_cost(vector<vector<pair<int, int>>> to) {
  int n = to.size();
  rep(i, n) {
    cout << "from " << i << " : ";
    for (auto p : to[i]) {
      cout << "(to " << p.first << ",cost " << p.second << ") ";
    }
    cout << endl;
  }
}

void print_maze(vector<vector<char>> maze) {
  int n = maze.size();
  int m = maze[0].size();
  rep(i, n) {
    rep(j, m) { cout << maze[i][j]; }
    cout << endl;
  }
}

void print_vector_vector_pair(vector<vector<pair<int, int>>> vvp) {
  for (vector<pair<int, int>> vp : vvp) {
    for (pair<int, int> p : vp) {
      cout << "(" << p.first << "," << p.second << ")"
           << " ";
    }
  }
  cout << endl;
}

void print_vector_vector(vector<vector<int>> vv) {
  for (vector<int> v : vv) {
    for (int i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

void print_vector_pair(vector<pair<int, int>> v) {
  for (pair<int, int> i : v) {
    cout << "(" << i.first << "," << i.second << ")"
         << " ";
  }
  cout << endl;
}

void print_vector_ll(vector<ll> v) {
  for (ll i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void print_queue(queue<int> q) {
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    cout << now << " ";
  }
  cout << endl;
}

void print_stack(stack<int> q) {
  while (q.size() > 0) {
    int now = q.top();
    q.pop();
    cout << now << " ";
  }
  cout << endl;
}

void print_priority_queue(priority_queue<int> q) {
  while (q.size() > 0) {
    int now = q.top();
    q.pop();
    cout << now << " ";
  }
  cout << endl;
}

vector<pair<int, char>> swapmap(map<char, int> mp) {
  vector<pair<int, char>> vp;
  for (auto p : mp) {
    vp.push_back(make_pair(p.second, p.first));
  }
  return vp;
}

ll rpow(ll a, ll r, ll mod) {
  if (r == 0)
    return 1;
  ll ans = rpow(a, r / 2, mod);
  ans *= ans;
  ans %= mod;
  if (r % 2 == 1)
    ans *= a;
  ans %= mod;
  return ans;
}

vector<ll> make_fact(int limit) {
  vector<ll> ans(limit, 1);
  rep(i, limit - 1) {
    ans[i + 1] = ans[i] * (i + 1);
    ans[i + 1] %= mod;
  }
  return ans;
}

vector<bool> make_erat(int limit) {
  vector<bool> erat(limit, true);
  erat[0] = false;
  erat[1] = false;
  for (int i = 0; i * i < limit; i++) {
    if (erat[i]) {
      int j = i * i;
      while (j < limit) {
        erat[j] = false;
        j += i;
      }
    }
  }
  return erat;
}

string binary_expression(int n, int d) {
  string ans = "";
  rep(i, d) { ans.push_back((n >> i & 1) + '0'); }
  return ans;
}

class segment_tree {
private:
  int sz;
  vector<int> seg;
  vector<int> lazy;
  void push(int k) {
    if (k < sz) {
      lazy[k * 2] = max(lazy[k * 2], lazy[k]);
      lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
    }
    seg[k] = max(seg[k], lazy[k]);
    lazy[k] = 0;
  }
  void update(int a, int b, int x, int k, int l, int r) {
    push(k);
    if (r <= a || b <= l)
      return;
    if (a <= l && r <= b) {
      lazy[k] = x;
      push(k);
      return;
    }
    update(a, b, x, k * 2, l, (l + r) >> 1);
    update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
    seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
  }
  int range_max(int a, int b, int k, int l, int r) {
    push(k);
    if (r <= a || b <= l)
      return 0;
    if (a <= l && r <= b)
      return seg[k];
    int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
    int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
    return max(lc, rc);
  }

public:
  segment_tree() : sz(0), seg(), lazy(){};
  segment_tree(int N) {
    sz = 1;
    while (sz < N) {
      sz *= 2;
    }
    seg = std::vector<int>(sz * 2, 0);
    lazy = std::vector<int>(sz * 2, 0);
  }
  void update(int l, int r, int x) { update(l, r, x, 1, 0, sz); }
  int range_max(int l, int r) { return range_max(l, r, 1, 0, sz); }
};