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

vector<pair<ll,ll>> prime_factorize(ll n){
  vector<pair<ll,ll>> ans;
  for(ll i=2;i*i<=n;i++){
    if(n%i == 0){
      ll ex = 0;
      while(n%i == 0){
        ex ++;
        n /= i;
      }
      ans.push_back({i, ex});
    }
  }
  if(n != 1){
    ans.push_back({n,1});
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  rep1(i,n){
    vector<pair<ll,ll>> v = prime_factorize(i);
    int tmp = 0;
    for(auto p : v){
      tmp += p.second;
    }
    cout << tmp+1 << " ";
  }
  cout << endl;
}