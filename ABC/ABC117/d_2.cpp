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
void chmax(T &a, T b) { a = max(a, b); }

ll solve(vector<ll> buc, vector<bool> kbit, ll n, int d)
{
    // debug(d);
    ll ans = 0;
    ll factor = 1;
    rep(i, 40)
    {
        if (i < d)
        {
            ans += max(buc[i], n - buc[i]) * factor;
        }
        else if (i == d)
        {
            ans += buc[i] * factor;
        }
        else
        {
            if (kbit[i])
            {
                ans += (n - buc[i]) * factor;
            }
            else
            {
                ans += buc[i] * factor;
            }
        }
        factor *= 2;
    }
    // debug(ans);
    return (ans);
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<ll> buc(40);
    rep(i, n)
    {
        rep(j, 40)
        {
            buc[j] += a[i] & 1;
            a[i] /= 2;
        }
    }
    ll ans = 0;
    vector<bool> kbit(40);
    rep(i, 40)
    {
        kbit[i] = k & 1;
        k /= 2;
    }
    for (int d = -1; d < 40; d++)
    {
        if (d != -1 && !kbit[d])
        {
            continue;
        }
        chmax(ans, solve(buc, kbit, n, d));
    }
    cout << ans << endl;
}