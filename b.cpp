#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

const ll mod = 1e9+7;

int main() {
  int n;
  ll k,p;
  cin >> k >> p;
  vector<vector<int>> dp(n+1,vector<int>(2,0));
  dp[0][0] = 1;
}