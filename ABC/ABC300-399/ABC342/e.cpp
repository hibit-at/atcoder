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
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
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
    int n = v.size();
    int m = v[0].size();
    int p = v[0][0].size();
    rep(k, p)
    {
        os << "k = " << k << endl;
        rep(i, n)
        {
            rep(j, m)
            {
                os << v[i][j][k];
                if (j < m - 1)
                {
                    os << " ";
                }
                else
                {
                    os << endl;
                }
            }
        }
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

template <typename T>
ostream &operator<<(ostream &os, queue<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, deque<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop_front();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, stack<T> st)
{
    while (st.size())
    {
        os << st.top() << " ";
        st.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T> pq)
{
    while (pq.size())
    {
        os << pq.top() << " ";
        pq.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T, vector<T>, greater<T>> mpq)
{
    while (mpq.size())
    {
        os << mpq.top() << " ";
        mpq.pop();
    }
    return os;
}

#include <cassert>

ll validate(ll n, ll L, ll d)
{
    ll ng = 0;
    ll ok = 1e9;
    while (abs(ng - ok) > 1)
    {
        ll mid = ng + ok;
        mid /= 2;
        if (L + d * mid >= n)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    return L + d * ok;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> L(m), d(m), k(m), c(m), a(m), b(m);
    rep(i, m)
    {
        cin >> L[i] >> d[i] >> k[i] >> c[i] >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    // debug(L);
    // debug(d);
    // debug(k);
    // debug(c);
    // debug(a);
    // debug(b);
    rep(i, m);
    vector<vector<pair<ll, ll>>> to(n, vector<pair<ll, ll>>());
    rep(i, m)
    {
        ll u = a[i];
        ll v = b[i];
        to[v].push_back({u, i}); // i ... edge_idx
    }
    // cout << to << endl;
    priority_queue<pair<ll, ll>> q;
    q.push({ll(2e18), n - 1});
    vector<ll> dp(n, -1);
    while (q.size())
    {
        auto [now_cost, now_pos] = q.top();
        // debug(q.top());
        q.pop();
        if (now_cost <= dp[now_pos])
        {
            continue;
        }
        dp[now_pos] = now_cost;
        for (auto [next_pos, edge_idx] : to[now_pos])
        {
            // debug(next_pos);
            // debug(edge_idx);
            ll start = L[edge_idx];
            ll duration = d[edge_idx];
            ll trains = k[edge_idx];
            ll need_time = c[edge_idx];
            assert(a[edge_idx] == next_pos);
            assert(b[edge_idx] == now_pos);
            ll max_time = start + (trains - 1) * duration;
            // debug(max_time);
            ll ok = -1;
            ll ng = 2e18;
            while (abs(ng - ok) > 1)
            {
                ll mid = ng + ok;
                mid /= 2;
                // debug(mid);
                if (mid > max_time)
                {
                    ng = mid;
                    continue;
                }
                ll valid_start;
                if (mid < start)
                {
                    valid_start = start;
                }
                else
                {
                    valid_start = validate(mid, start, duration);
                }
                // debug(valid_start);
                if (valid_start + need_time <= dp[now_pos])
                {
                    ok = mid;
                }
                else
                {
                    ng = mid;
                }
            }
            // debug(ok);
            if (ok <= dp[next_pos])
            {
                continue;
            }
            q.push({ok, next_pos});
        }
    }
    // cout << dp << endl;
    rep(i, n - 1)
    {
        ll ans = dp[i];
        if (ans == -1)
        {
            cout << "Unreachable" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}