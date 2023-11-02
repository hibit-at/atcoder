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

vector<ll> divisor(ll n)
{
    vector<ll> ans;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i * i != n)
            {
                ans.push_back(n / i);
            }
        }
    }
    sort(all(ans));
    return ans;
}

int main(void)
{
    ll n;
    cin >> n;
    int ans = 0;
    rep1(i, n)
    {
        ll sq = i * i;
        // debug(sq);
        vector<ll> div = divisor(i);
        set<ll> div2;
        for (ll d : div)
        {
            for (ll e : div)
            {
                div2.insert(d * e);
            }
        }
        auto print_vector = [](auto v)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        };
        // print_vector(div2);
        for (ll d : div2)
        {
            ll e = sq / d;
            if (e <= n && d <= n)
            {
                // debug(d);
                // debug(e);
                ans++;
            }
        }
    }
    cout << ans << endl;
}
