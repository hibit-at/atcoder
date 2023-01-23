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
#include <complex>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << endl;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << "i = " << i << endl;
        os << v[i];
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

template <typename T, typename S>
ostream &operator<<(ostream &os, map<T, S> &mp)
{
    for (auto &[key, val] : mp)
    {
        os << key << ":" << val << " ";
    }
    cout << endl;
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, multiset<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

int main()
{
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> a(n);
    cin >> a;
    vector<pair<int, int>> order(n);
    rep(i, n)
    {
        order[i] = {a[i], i};
    }
    sort(all(order));
    // debug(order);
    // debug(a);
    ll ng = -1;
    ll ok = ll(1e18);
    while (abs(ng - ok) > 1)
    {
        ll mid = ng + ok;
        mid /= 2;
        // debug(mid);
        ll criteria = 0;
        rep(i, n)
        {
            criteria += min(a[i], mid);
        }
        if (criteria >= k)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    // debug(ok);
    ll ideal = 0;
    rep(i, n)
    {
        ideal += min(a[i], ok);
    }
    // debug(ideal);
    ll remainder = ideal - k;
    // debug(remainder);
    vector<ll> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = max(0LL, a[i] - ok);
    }
    rep(i, n)
    {
        order[i].first -= ok;
    }
    // debug(order);
    if (remainder > 0)
    {
        rep(i, n)
        {
            if (order[i].first < 0)
            {
                continue;
            }
            ans[order[i].second]++;
            remainder--;
            if (remainder == 0)
            {
                break;
            }
        }
    }
    cout << ans << endl;
}