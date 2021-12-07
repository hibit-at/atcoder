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


int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<bool>> adj(n, vector<bool>(n));
  rep(i, n)
  {
    string s;
    cin >> s;
    rep(j, n)
    {
      if (s[j] == 'o')
      {
        adj[i][j] = true;
        adj[j][i] = true;
      }
    }
  }
  if (adj[a][b])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}