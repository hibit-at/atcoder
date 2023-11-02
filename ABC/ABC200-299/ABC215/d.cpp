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

void chmax(int &a, int b) { a = max(a, b); }

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> ans;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ll ex = 0;
      while (n % i == 0) {
        ex++;
        n /= i;
      }
      ans.push_back({i, ex});
    }
  }
  if (n != 1) {
    ans.push_back({n, 1});
  }
  return ans;
}

void print_map(map<int, int> mp) {
  for (auto p : mp) {
    cout << "key : " << p.first << ", value : " << p.second << endl;
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;
  int max = 0;
  map<int, int> mp;
  vector<bool> erat(m+1,true);
  rep(i, n) {
    int a;
    cin >> a;
    if(a == 1){
      continue;
    }
    int cnt = 0;
    for(int i=2;i*i<=a;i++){
      if(a%i == 0){
        cnt ++;
        mp[i] = 1;
        mp[a/i] = 1;
      }
    }
    if(cnt == 0){
      mp[a] = 1;
    }
  }
  // print_map(mp);
  for(auto p : mp){
    int now = p.first;
    int span = p.first;
    while(now <= m){
      erat[now] = false;
      now += span;
    }
  }
  vector<int> ans;
  rep1(i,m){
    if(erat[i]){
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for(int a : ans){
    cout << a << endl;
  }
}