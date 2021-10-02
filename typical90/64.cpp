#include <algorithm>
#include <iostream>
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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

void print_vector(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main(void)
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b(n - 1);
    ll ans = 0;
    rep(i, n - 1)
    {
        b[i] = a[i + 1] - a[i];
        ans += (ll)abs(b[i]);
    }
    // debug(ans);
    // print_vector(b);
    rep(_, q)
    {
        // debug(_);
        ll l, r, v;
        cin >> l >> r >> v;
        ll border_L = l - 2;
        if (border_L >= 0)
        {
            ll pre_abs = abs(b[border_L]);
            b[border_L] += v;
            ll after_abs = abs(b[border_L]);
            ans += after_abs - pre_abs;
        }
        ll border_R = r - 1;
        if (border_R < n - 1)
        {
            ll pre_abs = abs(b[border_R]);
            b[border_R] -= v;
            ll after_abs = abs(b[border_R]);
            ans += after_abs - pre_abs;
        }
        // print_vector(b);
        cout << ans << endl;
    }
}