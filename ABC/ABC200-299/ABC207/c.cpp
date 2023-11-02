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

const ll mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> left(n),right(n);
  rep(i, n) {
    int t, l, r;
    cin >> t >> l >> r;
    l *= 2;
    r *= 2;
    if (t == 2) {
      r--;
    }
    if (t == 3) {
      l++;
    }
    if (t == 4) {
      r--;
      l++;
    }
    left[i] = l;
    right[i] = r;
  }
  int ans = 0;
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      ans += max(left[i],left[j]) <= min(right[i],right[j]);
    }
  }
  cout << ans << endl;
}