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
typedef long long ll;

void print_map(map<pair<ll, ll>, int> mp)
{
    for (auto p : mp)
    {
        cout << "key : " << p.first.first << "," << p.first.second << ", value : " << p.second << endl;
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    map<pair<ll, ll>, bool> mp;
    rep(i, n)
    {
        cin >> x[i] >> y[i];
        mp[{x[i], y[i]}] = true;
    }
    ll ans = 0;
    rep(i, n)
    {
        rep(j, n)
        {
            if (x[i] >= x[j])
            {
                continue;
            }
            if (y[i] >= y[j])
            {
                continue;
            }
            ans += mp[{x[i], y[j]}] && mp[{x[j], y[i]}];
        }
    }
    cout << ans << endl;
}