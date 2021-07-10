#include <algorithm>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const ll mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<ll> c(n);
  rep(i,n){
    cin >> c[i];
  }
  ll ans = 1;
  rep(i,n){
    ans *= (c[i]-i);
    ans %= mod;
  }
  cout << ans << endl;
}