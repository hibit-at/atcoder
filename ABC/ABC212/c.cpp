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
const ll inf = 2e9;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) { cin >> a[i]; }
  a.push_back(-inf);
  a.push_back(inf);
  sort(all(a));
  ll ans = inf;
  rep(i, m) {
    int b;
    cin >> b;
    // cout << b << endl;
    int ng = 0;
    int ok = n+1;
    while (abs(ng - ok) > 1) {
      int mid = (ng + ok) / 2;
      if (b >= a[mid]){
        ng = mid;
      }else{
        ok = mid;
      }
    }
    ll dif = min(b-a[ok-1],a[ok]-b);
    // cout << "ok pointer is " << ok << " and dif " << dif << endl;
    ans = min(ans,dif);
  }
  cout << ans << endl;
}