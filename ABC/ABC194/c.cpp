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
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

ll const mod = (ll)1e9 + 7;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n + 1), s(n + 1), d(n + 1), ds(n + 1);
  rep1(i, n)
  {
    ll x;
    cin >> x;
    a[i] = x;
    s[i] = x;
    d[i] = x * x;
    ds[i] = x * x;
    if (i > 1)
    {
      s[i] += s[i - 1];
      ds[i] += ds[i - 1];
    }
  }
  ll ans = 0;
  for (int i = 2; i <= n; i++)
  {
    ans += (i - 1) * d[i];
    ans -= 2 * a[i] * s[i - 1];
    ans += ds[i - 1];
  }
  cout << ans << endl;
}