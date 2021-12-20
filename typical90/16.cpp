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
  ll a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 1e4;
  rep(i, (int)1e4) {
    rep(j, (int)1e4) {
      ll rest = n - i * a - j * b;
      if (rest < 0) {
        continue;
      }
      if (rest % c == 0) {
        int rest_coin = rest / c;
        ans = min(ans, i + j + rest_coin);
      }
    }
  }
  cout << ans << endl;
}