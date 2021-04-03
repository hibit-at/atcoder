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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 2e9;
  rep(i, 1 << n) {
    if (i == 0) {
      continue;
    }
    bool topcheck = (i >> (n - 1)) & 1;
    if (!topcheck) {
      continue;
    }
    // cout << "now separtion is";
    // rep(j, n) { cout << (i >> j & 1); }
    // cout << endl;
    ll total_xor = 0;
    ll part_or = 0;
    rep(j, n) {
      part_or |= a[j];
    //   cout << "...part_or is " << part_or << " till pos " << j << endl;
      bool bit = i >> j & 1;
      //   cout << bit;
      if (bit) {
        total_xor ^= part_or;
        // cout << "...wall hit at " << j << " now total_xor is " << total_xor
            //  << endl;
        part_or = 0;
      }
    }
    // cout << i << " " << total_xor << endl;
    ans = min(ans, total_xor);
    // cout << endl;
  }
  cout << ans << endl;
}