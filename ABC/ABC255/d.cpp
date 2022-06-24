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
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

int main(void)
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    cin >> a;
    sort(all(a));
    vector<ll> s(n + 1);
    rep(i, n)
    {
        s[i + 1] += s[i] + a[i];
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // print_vector(a);
    // print_vector(s);
    while (q--)
    {
        ll x;
        cin >> x;
        ll border = upper_bound(all(a), x) - a.begin();
        // debug(border);
        ll ans = 0;
        ll left = s[border];
        ll right = s[n] - s[border];
        ans += right - x * (n - border);
        ans += x * border - left;
        // debug(ans);
        cout << ans << endl;
    }
}