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
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> a(n + 1, 0);
  a.push_back(l);
  rep1(i, n) cin >> a[i];
  int ok = 0;
  int ng = l;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    int tmp = 0;
    int pieces = 0;
    rep1(i, n + 1) {
      tmp += a[i] - a[i - 1];
      if (tmp >= mid) {
        pieces++;
        tmp = 0;
      }
    }
    if (pieces >= k + 1) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
}