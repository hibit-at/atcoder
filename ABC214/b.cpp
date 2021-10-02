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

int main(void) {
  int s, t;
  cin >> s >> t;
  int ans = 0;
  rep(a, 101) {
    rep(b, 101) {
      rep(c, 101) {
        if (a + b + c <= s && a * b * c <= t) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}