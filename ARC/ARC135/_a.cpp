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
void chmax(T &a, T b) { a = max(a, b); }

const ll mod = 998244353;

map<ll, ll> memo;

ll dfs(ll n)
{
    if (n == 1)
    {
        return 1;
    }
    if (memo[n] > 0)
    {
        return memo[n];
    }
    if (n <= 4)
    {
        return memo[n] = n;
    }
    ll n_minus = n / 2;
    ll n_plus = (n + 1) / 2;
    return memo[n] = dfs(n_minus) * dfs(n_plus) % mod;
}

int main(void)
{
    ll x;
    cin >> x;
    cout << dfs(x) << endl;
}