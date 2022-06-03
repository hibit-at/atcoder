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
    const int inf = 2e9;
    vector<int> dp(n + 1, inf);
    dp[0] = -1;
    rep(i, n)
    {
        int a;
        cin >> a;
        *lower_bound(all(dp), a) = a;
    }
    cout << --lower_bound(all(dp), inf) - dp.begin() << endl;
}