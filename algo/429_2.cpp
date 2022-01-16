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

ll L, R;
ll ans = 0;
vector<bool> memo;

void func(ll n)
{
    if (n > R)
    {
        return;
    }
    if (memo[n])
    {
        return;
    }
    // debug(n);
    if (L <= n && n <= R)
    {
        ans += n;
    }
    memo[n] = true;
    if (n % 10 < 9)
    {
        func(n + 1);
    }
    func(n * 10 + n % 10);
    return;
}

int main()
{
    cin >> L >> R;
    memo.resize(R + 1, false);
    func(0);
    cout << ans << endl;
}