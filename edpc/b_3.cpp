#include <algorithm>
#include <iomanip>
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

const int inf = 2e9;

void chmin(int &a, int b) { a = min(a, b); }

vector<int> h;
int n, k;
vector<int> dp;

int dfs(int now){
  if(now == 0){
    return 0;
  }
  if(dp[now] < inf){
    return dp[now];
  }
  int ans = inf;
  rep(i,k){
    int from = now - i - 1;
    if(from < 0){
      break;
    }
    chmin(ans, dfs(from)+abs(h[now]-h[from]));
  } 
  return dp[now] = ans;
}

int main() {
  cin >> n >> k;
  h.resize(n);
  dp.resize(n,inf);
  rep(i, n) cin >> h[i];
  cout << dfs(n-1) << endl;
}