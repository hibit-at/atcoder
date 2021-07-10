#include <algorithm>
#include <deque>
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

int main()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  rep(i,q){
    ll k;
    cin >> k;
    ll ng = 0;
    ll ok = 2e18+1;
    while(abs(ng-ok)>1){
      ll mid = (ng+ok)/2;
      ll shift = upper_bound(all(a),mid) - a.begin();
      if (mid-shift >= k){
        ok = mid;
      }else{
        ng = mid;
      }
    }
    cout << ok << endl;
  }
}