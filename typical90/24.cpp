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
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  int dif = 0;
  rep(i, n) dif += abs(a[i] - b[i]);
  //   cout << "orig dif " << dif << endl;
  if (k < dif) {
    cout << "No" << endl;
    return 0;
  }
  k -= dif;
  //   cout << "rest k " << k << endl;
  if (k % 2 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}