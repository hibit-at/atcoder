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

ll mod = (ll)1e9+7;

int main(){
  ll n,p;
  cin >> n >> p;
  ll ans = 1;
  rep(i,n){
    if(i == 0){
      ans = p-1;
      continue;
    }
    ans = ans*(p-2);
    ans %= mod;
  }
  cout << ans << endl;
}