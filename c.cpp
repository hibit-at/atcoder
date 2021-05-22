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

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n), c(n + 1);
  vector<ll> buc_b(n + 1);
  rep(i, n) { cin >> a[i]; }
  rep(i, n) {
    cin >> b[i];
  }
  rep(i, n) {
    ll x;
    cin >> x;
    c[x]++;
  }
  rep(i,n){
    int x = b[i];
    buc_b[x] += c[i+1];
  }
  ll ans = 0;
  rep(i, n) {
    ans += buc_b[a[i]];
  }
  cout << ans << endl;
}