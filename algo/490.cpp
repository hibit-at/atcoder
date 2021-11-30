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
const int inf = 1e18;

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

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

template <typename S, typename T>
void print_vector_pair(vector<pair<S, T>> v)
{
  for (pair<S, T> i : v)
  {
    cout << "(" << i.first << "," << i.second << ")"
         << " ";
  }
  cout << endl;
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    // print_vector<int>(a);
    ll ans = inf;
    rep(start, n)
    {
        int end = start + k - 1;
        // debug(a[end]);
        // debug(a[start]);
        if (end >= n)
        {
            break;
        }
        chmin<ll>(ans, a[end] - a[start]);
    }
    cout << ans << endl;
}