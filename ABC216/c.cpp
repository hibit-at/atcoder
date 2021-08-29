#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

int n;

int main()
{
  cin >> n;
  string ans;
  while (n > 1)
  {
    if (n % 2 == 0)
    {
      ans.push_back('B');
      n /= 2;
    }
    else
    {
      ans.push_back('A');
      n--;
    }
  }
  ans.push_back('A');
  reverse(all(ans));
  cout << ans << endl;
}