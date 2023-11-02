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
#include <atcoder/modint>

using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;



void solve()
{
    int n;
    string s;
    cin >> n >> s;
    modint998244353 ans = 0;
    int m = (n + 1) / 2;
    rep(i, m)
    {
        ans *= 26;
        ans += s[i] - 'A';
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
    }
    cout << ans.val() << endl;
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