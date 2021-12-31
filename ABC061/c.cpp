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

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    return;
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    vector<ll> keys, values, value_sums;
    for (auto p : mp)
    {
        keys.push_back(p.first);
        values.push_back(p.second);
    }
    value_sums.resize(mp.size());
    rep(i, mp.size())
    {
        value_sums[i] = values[i];
        if (i > 0)
        {
            value_sums[i] += value_sums[i - 1];
        }
    }
    auto itr = lower_bound(all(value_sums), k);
    ll where = itr - value_sums.begin();
    cout << keys[where] << endl;
}