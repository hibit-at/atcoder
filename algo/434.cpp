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

vector<vector<int>> to;

int dfs(int now)
{
  int ans = 1;
  for (int next : to[now])
  {
    ans += dfs(next);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  to.resize(n);
  rep1(i, n - 1)
  {
    int p;
    cin >> p;
    to[p].push_back(i);
  }
  rep(i, n)
  {
    cout << dfs(i) - 1 << endl;
  }
}