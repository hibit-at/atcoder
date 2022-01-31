#include <algorithm>
#include <iostream>
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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (c * d == b) {
    cout << -1 << endl;
    return 0;
  }
  int ans = (a + c * d - b - 1) / (c * d - b);
  if (ans > 0) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}