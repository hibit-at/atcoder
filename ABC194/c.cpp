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

ll const mod = (ll)1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  //   rep(i, n) a[i] = i + 1;
  sort(all(a));
  ll ans = 0;
  for (int diff = 1; diff < n; diff++) {
    for (int i = 0; i + diff < n; i++) {
      ans += (a[i + diff] - a[i]) * (a[i + diff] - a[i]);
    }
  }
  cout << ans << endl;
}