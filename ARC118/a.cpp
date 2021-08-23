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
  ll t;
  ll n;
  cin >> t >> n;
  ll tmax = 100 + t;
  vector<bool> erat(tmax + 1, true);
  rep1(i, tmax) {
    int tax = i * (100 + t) / 100;
    erat[tax] = false;
  }
  vector<int> imp;
  rep1(i, tmax) {
    if (erat[i]) {
      imp.push_back(i);
    }
  }
  n--;
  ll loop = n / imp.size();
  ll mod = n % imp.size();
  cout << loop * tmax + imp[mod] << endl;
}