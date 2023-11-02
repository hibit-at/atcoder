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

const ll mod = 998244353;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    int m = (n + 1) / 2;
    rep(i, m)
    {
        ans *= 26;
        ans %= mod;
        ans += s[i] - 'A';
        ans %= mod;
    }
    string t = "";
    rep(i, m)
    {
        t.push_back(s[i]);
    }
    string r = t;
    if (n % 2)
    {
        r.pop_back();
    }
    reverse(all(r));
    rep(i, n - m)
    {
        t.push_back(r[i]);
    }
    if (t <= s)
    {
        ans++;
        ans %= mod;
    }
    // debug(t);
    // debug(ans);
    cout << ans << endl;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}