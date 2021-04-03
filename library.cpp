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

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

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

void print_maze(vector<vector<char>> maze) {
  int n = maze.size();
  int m = maze[0].size();
  rep(i, n) {
    rep(j, m) { cout << maze[i][j]; }
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

int pop_count(int n) {
  int ans = 0;
  rep(i, 32) { ans += (n >> i & 1); }
  return ans;
}

int main() {
  vector<bool> erat = make_erat(200001);
  rep(i, 100) {
    if (erat[i])
      cout << i << endl;
  }
}