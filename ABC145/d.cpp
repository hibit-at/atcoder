#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

const ll mod = (ll)1e9 + 7;

ll rpow(ll a, ll r) {
  if (r == 0)
    return 1;
  ll ans = rpow(a, r / 2);
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

void print_vector(vector<ll> v) {
  for (ll i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  ll x, y;
  cin >> x >> y;
  if ((x + y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll tx = (-x + 2 * y) / 3;
  ll ty = (2 * x - y) / 3;
  if (tx < 0 || ty < 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> fact = make_fact(1e6);
  ll ans = fact[tx + ty];
  ans *= rpow(fact[tx], mod - 2);
  ans %= mod;
  ans *= rpow(fact[ty], mod - 2);
  ans %= mod;
  cout << ans << endl;
}