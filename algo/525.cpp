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

vector<int> par;

int dfs(int now)
{
  if (par[now] == -1)
  {
    return 0;
  }
  int p = par[now];
  return 1 + dfs(p);
}

int main()
{
  int n;
  cin >> n;
  par.resize(n);
  par[0] = -1;
  rep1(i, n - 1)
  {
    cin >> par[i];
  }
  rep(i, n)
  {
    cout << dfs(i) << endl;
  }
}