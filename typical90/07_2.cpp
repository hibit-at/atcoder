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
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

int main(void)
{
  int n;
  cin >> n;
  set<int> st;
  rep(i, n)
  {
    int a;
    cin >> a;
    st.insert(a);
  }
  int q;
  cin >> q;
  while (q--)
  {
    int b;
    cin >> b;
    auto itr = st.lower_bound(b);
    // debug(*itr);
    if (itr == st.end())
    {
      cout << b - *prev(itr) << endl;
    }
    else if (itr == st.begin())
    {
      cout << *itr - b << endl;
    }
    else
    {
      cout << min(*itr - b, b - *prev(itr)) << endl;
    }
  }
}