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

int main() {
  int n;
  cin >> n;
  ll plus = 0;
  ll lower = -1e17;
  ll upper = 1e17;
  rep(i, n) {
    ll a, t;
    cin >> a >> t;
    if (t == 1) {
      lower = max((ll)-1e17,lower+a);
      upper = min((ll)1e17,upper+a);
      plus += a;

    }
    if (t == 2) {
      lower = max(lower, a);
      if(lower > upper) upper = lower;
    }
    if (t == 3) {
      upper = min(upper, a);
      if(upper < lower) lower = upper;
    }
    // cout << "lower is " << lower << ", upper is " << upper << endl;
    // cout << "...plus is " << plus << endl;
  }
  int q;
  cin >> q;
  rep(i, q) {
    ll x;
    cin >> x;
    ll ans = x + plus;
    if (ans > upper) {
      cout << upper << endl;
    } else if (ans < lower) {
      cout << lower << endl;
    } else {
      cout << ans << endl;
    }
  }
}