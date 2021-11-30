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

template <typename T>
void print_set(set<T> st)
{
  for (int s : st)
  {
    cout << s << ",";
  }
  cout << endl;
}

template <typename S, typename T>
void print_map(map<S, T> mp)
{
  for (auto p : mp)
  {
    cout << "key : " << p.first << ", value : " << p.second << endl;
  }
}

int main(void)
{
  ll n;
  cin >> n;
  vector<ll> origin(n);
  set<ll> a;
  rep(i, n)
  {
    ll x;
    cin >> x;
    a.insert(x);
    origin[i] = x;
  }
  // print_set<ll>(a);
  map<ll, int> mp;
  int cnt = a.size() - 1;
  for (ll x : a)
  {
    mp[x] = cnt;
    cnt--;
  }
  // print_map<ll, int>(mp);
  rep(i, n)
  {
    cout << mp[origin[i]] << endl;
  }
}