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

int main(void)
{
  int n;
  cin >> n;
  vector<int> buc(n);
  rep(i, n)
  {
    int a;
    cin >> a;
    buc[a]++;
  }
  // print_vector(buc);
  vector<pair<int, int>> vp(n);
  rep(i, n)
  {
    vp[i].first = buc[i];
    vp[i].second = -i;
  }
  sort(all(vp));
  reverse(all(vp));
  rep(i, n)
  {
    cout << -vp[i].second << ' ' << vp[i].first << endl;
  }
}