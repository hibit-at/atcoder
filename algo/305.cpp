#include <algorithm>
#include <iostream>
#include <iomanip>
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

const int inf = 1e9;

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

template <typename T>
void print_vector(vector<T> v)
{
  for (T i : v)
  {
    cout << i << ",";
  }
  cout << endl;
  return;
}

int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  rep(i, n)
  {
    if (i + 1 <= n)
      dp[i + 1] += dp[i];
    if (i + 2 <= n)
      dp[i + 2] += dp[i];
    if (i + 2 <= n)
      dp[i + 3] += dp[i];
  }
  cout << dp.back() << endl;
}