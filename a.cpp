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

int main() {
  ll n, k;
  cin >> n >> k;
  vector<pair<int,int>> a(n);
  rep(i,n){
    int x;
    cin >> x;
    a[i] = {x,i};
  }
  sort(all(a));
  map<int,ll> mp;
  ll res = k % n;
  rep(i,n){
    mp[a[i].second] = k / n;
    if(res > 0){
      mp[a[i].second] ++;
    }
    res --;
  }
  rep(i,n){
    cout << mp[i] << endl;
  }
}