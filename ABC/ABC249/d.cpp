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
    map<ll, ll> count;
    rep(i, n)
    {
        ll a;
        cin >> a;
        count[a]++;
    }
    ll ans = 0;
    for (auto p : count)
    {
        ll key = p.first;
        ll val = p.second;
        vector<ll> div = divisor(key);
        for (ll d : div)
        {
            ll plus = val * count[d] * count[key / d];
            ans += plus;
        }
    }
    cout << ans << endl;
}