#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

ll mod = (ll)pow(10, 9) + 7;

double heron(pair<int, int> start, pair<int, int> target1,
             pair<int, int> target2) {
  target1.first -= start.first;
  target1.second -= start.second;
  target2.first -= start.first;
  target2.second -= start.second;
  return abs(target1.first * target2.second - target2.first * target1.second);
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

int main() {
  ll a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  ll scale = n / 8;
  n %= 8;
  ll base = 0;
  if (n == 0) {
    base = b + d;
  }
  if (n == 1) {
    base = 2 * b;
  }
  if (n == 2) {
    base = 2 * b - 2 * c;
  }
  if (n == 3) {
    base = -4 * c;
  }
  if (n == 4) {
    base = -4 * a - 4 * c;
  }
  if (n == 5) {
    base = -8 * a;
  }
  if (n == 6) {
    base = -8 * a + 8 * d;
  }
  if (n == 7) {
    base = 16 * d;
  }
  scale = rpow(16, scale, mod);
  ll ans = scale * base;
  ans %= mod;
  ans += mod;
  ans %= mod;
  cout << ans << endl;
}