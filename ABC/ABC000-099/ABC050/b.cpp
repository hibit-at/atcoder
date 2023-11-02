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

template <typename T>
void print_vector(vector<T> v)
{
for (T i : v)
  {
    cout << i << ',';
  }
  cout << endl;
  return;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n)
    {
        cin >> t[i];
    }
    int sum = accumulate(all(t),0);
    int m;
    cin >> m;
    rep(i, m)
    {
        int p, x;
        cin >> p >> x;
        p--;
        cout << sum + x - t[p] << endl;
    }
}