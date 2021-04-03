#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<int> buc(31,0);
  rep(i,n){
    rep(j,31){
      buc[j] += a[i]>>j&1;
    }
  }
  ll ans = 0;
  rep(i,31){
    if(buc[i] == 1){
      cout << (1<<i) << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}