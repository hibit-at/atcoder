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
    cout << i << ",";
  }
  cout << endl;
  return;
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
  int x = n / 2 - 1;
  while (x >= 0)
  {
    // debug(x);
    int k = x;
    while (true)
    {
      // debug(k);
      vector<pair<int, int>> children;
      vector<int> child_place = {k, 2 * k + 1, 2 * k + 2};
      for (int c : child_place)
      {
        if (c < n)
        {
          children.push_back({-a[c], c});
        }
      }
      if (children.size() == 1)
      {
        break;
      }
      sort(all(children));
      // print_vector_pair<int, int>(children);
      int target = children[0].second;
      if(k == target){
        break;
      }
      swap(a[k], a[target]);
      swap(k, target);
    }
    // print_vector(a);
    x--;
  }
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