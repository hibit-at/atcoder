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
    vector<ll> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    int ans = 0;
    map<ll, int> mp;
    rep(i, n)
    {
        if (a[i] == b[i])
        {
            ans++;
        }
        mp[b[i]]++;
    }
    cout << ans << endl;
    int res = 0;
    rep(i, n)
    {
        res += mp[a[i]];
    }
    // debug(res);
    res -= ans;
    cout << res << endl;
}