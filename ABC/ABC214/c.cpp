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

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

int main(void)
{
    int n;
    cin >> n;
    vector<ll> s(n), t(n);
    rep(i, n)
    {
        cin >> s[i];
    }
    const ll inf = 1e18;
    vector<ll> dp(n, inf);
    rep(i, n)
    {
        ll t;
        cin >> t;
        dp[i] = t;
    }
    auto start = min_element(all(dp)) - dp.begin();
    // debug(start)
    // print_vector(dp);
    rep(i, n)
    {
        // debug((i + start) % n);s
        chmin(dp[(i + 1 + start) % n], dp[(i + start) % n] + s[(i + start) % n]);
    }
    // print_vector(dp);
    rep(i, n)
    {
        cout << dp[i] << endl;
    }
}