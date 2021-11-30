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
    cout << i << " ";
  }
  cout << endl;
  return;
}

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  vector<ll> num(n+1);
  rep(i, n)
  {
    num[a[i]]++;
  }
  // print_vector(num);
  vector<ll> b;
  rep(i, n+1)
  {
    rep(j, num[i])
    {
      b.push_back(i);
    }
  }
  print_vector(b);
}