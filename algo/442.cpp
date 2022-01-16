#include <algorithm>
#include <iostream>
<<<<<<< HEAD
=======
#include <iomanip>
>>>>>>> 3b87184c338a56f738f0caf54f2233e0c268bd17
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

vector<int> quick(vector<int> v)
{
  int n = v.size();
  int x = n / 2;
  int axis = v[x];
  // print_vector(v);
  vector<int> sort_L = {};
  vector<int> sort_R = {};
  rep(i, n)
  {
    if (i == x)
    {
      continue;
    }
    if (v[i] < axis)
    {
      sort_L.push_back(v[i]);
    }
    else
    {
      sort_R.push_back(v[i]);
    }
  }
  if (sort_L.size() > 0)
  {
    sort_L = quick(sort_L);
  }
  if (sort_R.size() > 0)
  {
    sort_R = quick(sort_R);
  }
  sort_L.push_back(axis);
  sort_L.insert(sort_L.end(), all(sort_R));
  return sort_L;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  a = quick(a);
  rep(i, n)
  {
    cout << a[i];
    if (i < n - 1)
    {
      cout << ' ';
    }
    else
    {
      cout << endl;
    }
  }
}