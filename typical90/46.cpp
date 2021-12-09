#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  vector<ll> buc_a(46), buc_b(46), buc_c(46);
  rep(i, n) { buc_c[c[i] % 46]++; }
  rep(i, n) {
    rep(j, 46) { buc_b[(j + b[i]) % 46] += buc_c[j]; }
  }
  rep(i, n) {
    rep(j, 46) { buc_a[(j + a[i]) % 46] += buc_b[j]; }
  }
  cout << buc_a[0] << endl;
}