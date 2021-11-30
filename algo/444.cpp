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
#include <deque>

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

template <typename T>
void print_deque(deque<T> q)
{
  while (q.size() > 0)
  {
    T now = q.front();
    q.pop_front();
    cout << now << ",";
  }
  cout << endl;
}

vector<int> quick(vector<int> a)
{
  int n = a.size();
  int x = n / 2;
  vector<int> L = {};
  vector<int> R = {};
  rep(i, n)
  {
    if (i < x)
    {
      L.push_back(a[i]);
    }
    else
    {
      R.push_back(a[i]);
    }
  }
  if (L.size() > 1)
  {
    L = quick(L);
  }
  if (R.size() > 1)
  {
    R = quick(R);
  }
  reverse(all(L));
  reverse(all(R));
  deque<int> dq;
  rep(i, L.size())
  {
    dq.push_back(L[i]);
  }
  rep(i, R.size())
  {
    dq.push_front(R[i]);
  }
  vector<int> b = {};
  while (dq.size() > 0)
  {
    int e_first = dq.front();
    int e_last = dq.back();
    if (e_first <= e_last)
    {
      b.push_back(e_first);
      dq.pop_front();
    }
    else
    {
      b.push_back(e_last);
      dq.pop_back();
    }
  }
  return b;
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