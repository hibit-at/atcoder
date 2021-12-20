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

template <typename S, typename T>
void print_vector_pair(vector<pair<S, T>> v)
{
  for (pair<S, T> i : v)
  {
    cout << "(" << i.first << "," << i.second << ")"
         << " ";
  }
  cout << endl;
}

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

void make_heap(vector<int> &a)
{
  int n = a.size();
  int x = n / 2 - 1;
  while (x >= 0)
  {
    int k = x;
    while (true)
    {
      vector<pair<int, int>> children;
      vector<int> where_children = {k, 2 * k + 1, 2 * k + 2};
      for (int w : where_children)
      {
        if (w < n)
        {
          children.push_back({-a[w], w});
        }
      }
      if (children.size() == 1)
      {
        break;
      }
      sort(all(children));
      int target = children[0].second;
      if (k == target)
      {
        break;
      }
      swap(a[k], a[target]);
      swap(k, target);
    }
    x--;
  }
}

void pop_heap(vector<int> &a, int n)
{
  swap(a[0], a[n]);
  int k = 0;
  while (true)
  {
    vector<pair<int, int>> children;
    vector<int> where_children = {k, 2 * k + 1, 2 * k + 2};
    for (int w : where_children)
    {
      if (w < n)
      {
        children.push_back({-a[w], w});
      }
    }
    if (children.size() == 1)
    {
      break;
    }
    sort(all(children));
    int target = children[0].second;
    if (k == target)
    {
      break;
    }
    swap(a[k], a[target]);
    swap(k, target);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  rep(i, n)
  {
    if (i == 0)
    {
      make_heap(a);
    }
    else
    {
      pop_heap(a, n - i);
    }
    // debug(i);
    if (n - i == m)
    {
      print_vector(a);
    }
  }
  print_vector<int>(a);
}