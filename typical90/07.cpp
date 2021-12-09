#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
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

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  rep1(i, n) { cin >> a[i]; }
  sort(all(a));
  int q;
  cin >> q;
  ll ans = 0;
  rep(i, q) {
    ll b;
    cin >> b;
    ll ok = 0;
    ll ng = n + 1;
    while (abs(ng - ok) > 1) {
      ll mid = (ng + ok) / 2;
      if (b >= a[mid]) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    // cout << "ok is " << a[ok] << ", ng is " << a[ng] << endl;
    if (ok == 0) {
      ans = a[ng] - b;
    } else if (ok == n) {
      ans = b - a[ok];
    } else {
      ans = min(a[ng] - b, b - a[ok]);
    }
    cout << ans << endl;
  }
}