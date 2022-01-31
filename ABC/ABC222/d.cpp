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
#include <stack>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

const ll mod = 998244353;

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
  for (vector<T> v : vv)
  {
    for (int i : v)
    {
      cout << i << ",";
    }
    cout << endl;
  }
}


template <typename T>
void print_vector(vector<T> v)
{
  for (ll i : v)
  {
    cout << i << ",";
  }
  cout << endl;
  return;
}

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    int lim = 3030;
    vector<vector<ll>> dp(n,vector<ll>(lim,0));
    for(int i=a[0];i<=b[0];i++){
        dp[0][i] = 1;
    }
    rep(i,n-1){
        rep(j,lim){
            // debug(j);
            // debug(a[i+1]);
            int start = max(j,a[i+1]);
            int end = b[i+1];
            ll now = dp[i][j];
            dp[i+1][start] += now;
            dp[i+1][start] %= mod;
            dp[i+1][end+1] -= now;
            dp[i+1][end+1] %= mod;
        }
        rep(j,lim-1){
            dp[i+1][j+1] += dp[i+1][j];
            dp[i+1][j+1] %= mod;
        }
    }
    // print_vector_vector<ll>(dp);
    ll ans = 0;
    rep(j,lim){
        ans += dp[n-1][j];
        ans %= mod;
    }
    cout << ans << endl;
}