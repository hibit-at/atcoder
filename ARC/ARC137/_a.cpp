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
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

ll dfs(ll L, ll R)
{
    if (L == R)
    {
        return 0;
    }
    if (gcd(L, R) == 1)
    {
        return R - L;
    }
    return max(dfs(L + 1, R), dfs(L, R - 1));
}

int main(void)
{
    ll L, R;
    cin >> L >> R;
    cout << dfs(L, R) << endl;
}