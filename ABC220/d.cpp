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

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(10,0));
    dp[0][a[0]] = 1;
    rep(i,n-1){
        rep(j,10){
            int now = j;
            int next = a[i+1];
            int f = (now + next) % 10;
            int g = (now * next) % 10;
            dp[i+1][f] += dp[i][j];
            dp[i+1][f] %= mod;
            dp[i+1][g] += dp[i][j];
            dp[i+1][g] %= mod;
        }
    }
    // print_vector_vector<int>(dp);
    rep(j,10){
        cout << dp[n-1][j] << endl;
    }
}