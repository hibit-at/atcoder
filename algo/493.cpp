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
  int n;
  cin >> n;
  vector<pair<pair<string, int>, int>> orig(n);
  vector<pair<pair<int, int>, int>> targ(n);
  rep(i, n)
  {
    string s;
    int a, b;
    cin >> s >> a >> b;
    orig[i] = {{s, a}, b};
    targ[i] = {{-a, a + b}, i};
  }
  sort(all(targ));
  rep(i, n)
  {
    int index = targ[i].second;
    auto o = orig[index];
    cout << o.first.first << ' ' << o.first.second << ' ' << o.second << endl;
  }
}