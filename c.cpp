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
  ll n;
  cin >> n;
  map<ll,ll> mp;
  rep(i,n){
    ll a;
    cin >> a;
    mp[a] ++;
  }
  ll ans = n*(n-1)/2;
  for(auto p : mp){
    ll m = p.second;
    ans -= m*(m-1)/2;
  }
  cout << ans << endl;
}