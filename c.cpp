#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  if (c % 2 == 0)
  {
    if (abs(a) > abs(b))
    {
      cout << '>' << endl;
      return 0;
    }
    if (abs(a) == abs(b))
    {
      cout << '=' << endl;
      return 0;
    }
    if (abs(a) < abs(b))
    {
      cout << '<' << endl;
      return 0;
    }
    return 0;
  }
  if (c % 2 == 1)
  {
    if (a < b)
    {
      cout << '<' << endl;
      return 0;
    }
    if (a == b)
    {
      cout << '=' << endl;
      return 0;
    }
    if (a > b)
    {
      cout << '>' << endl;
      return 0;
    }
    return 0;
  }
}