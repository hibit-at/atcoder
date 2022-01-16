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

int main(void)
{
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> vp(n);
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    vp[i] = {a, b};
  }
  sort(all(vp));
  ll ans = 0;
  rep(i, n)
  {
    ll a = vp[i].first;
    ll b = vp[i].second;
    if (k <= b)
    { //もう次の商品の数で十分な時
      ans += a * k;
      break;
    }
    else
    {
      ans += a * b;
      k -= b;
    }
  }
  cout << ans << endl;
}