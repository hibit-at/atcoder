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

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    ll ans = 0;
    rep(i, n)
    {
        auto itr = lower_bound(all(a), k - a[i]);
        ans += a.end()-itr;
    }
    cout << ans << endl;
}