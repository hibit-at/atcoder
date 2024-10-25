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

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> c(n);
    cin >> c;
    vector<ll> a(n);
    rep(i, n)
    {
        a[i] = s[i] == '1';
    }
    // debug(a);
    vector<ll> cost_01(n + 1);
    vector<ll> cost_10(n + 1);
    vector<int> seq_01(n);
    vector<int> seq_10(n);
    rep(i, n)
    {
        seq_01[i] = i % 2;
        seq_10[i] = 1 - i % 2;
    }
    // debug(seq_01);
    // debug(seq_10);
    rep(i, n)
    {
        cost_01[i + 1] = cost_01[i] + (a[i] != seq_01[i]) * c[i];
        cost_10[i + 1] = cost_10[i] + (a[i] != seq_10[i]) * c[i];
    }
    // debug(cost_01);
    // debug(cost_10);
    ll ans = 1e18;
    auto chmin = [](auto &a, auto b)
    { a = min(a, b); };
    rep(i, n - 1)
    {
        // 00_cost
        if (i % 2 == 0)
        {
            ll tmp = 0;
            tmp += cost_01[i];
            tmp += (a[i] != 0) * c[i];
            tmp += (a[i + 1] != 0) * c[i + 1];
            tmp += cost_10[n] - cost_10[i + 2];
            // debug(tmp);
            chmin(ans, tmp);
        }
        else
        {
            ll tmp = 0;
            tmp += cost_10[i];
            tmp += (a[i] != 0) * c[i];
            tmp += (a[i + 1] != 0) * c[i + 1];
            tmp += cost_01[n] - cost_01[i + 2];
            // debug(tmp);
            chmin(ans, tmp);
        }
    }
    rep(i, n - 1)
    {
        // 11_cost
        if (i % 2 == 0)
        {
            ll tmp = 0;
            tmp += cost_10[i];\
            tmp += (a[i] != 1) * c[i];
            tmp += (a[i + 1] != 1) * c[i + 1];
            tmp += cost_01[n] - cost_01[i + 2];
            // debug(tmp);
            chmin(ans,tmp);
        }
        else
        {
            ll tmp = 0;
            tmp += cost_01[i];
            tmp += (a[i] != 1) * c[i];
            tmp += (a[i + 1] != 1) * c[i + 1];
            tmp += cost_10[n] - cost_10[i + 2];
            // debug(tmp);
            chmin(ans,tmp);
        }
    }
    cout << ans << endl;
}