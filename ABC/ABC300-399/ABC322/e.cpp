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
    #define int ll
    int n, k, p;
    cin >> n >> k >> p;
    using VI = vector<ll>;
    using VVI = vector<VI>;
    using VVVI = vector<VVI>;
    using VVVVI = vector<VVVI>;
    using VVVVVI = vector<VVVVI>;
    using VVVVVVI = vector<VVVVVI>;
    VVVVVVI dp(n + 1, VVVVVI(p + 1, VVVVI(p + 1, VVVI(p + 1, VVI(p + 1, VI(p + 1, 1e18))))));
    dp[0][0][0][0][0][0] = 0;
    rep(i, n)
    {
        ll cost;
        cin >> cost;
        vector<int> v(5);
        rep(j, k)
        {
            cin >> v[j];
        }
        // debug(v);
        rep(a, p + 1)
        {
            rep(b, p + 1)
            {
                rep(c, p + 1)
                {
                    rep(d, p + 1)
                    {
                        rep(e, p + 1)
                        {
                            if (dp[i][a][b][c][d][e] == 1e18)
                            {
                                continue;
                            }
                            auto chmin = [](auto &a, auto b)
                            { a = min(a, b); };
                            chmin(dp[i + 1][a][b][c][d][e], dp[i][a][b][c][d][e]);
                            chmin(dp[i + 1][min(p, a + v[0])][min(p, b + v[1])][min(p, c + v[2])][min(p, d + v[3])][min(p, e + v[4])], dp[i][a][b][c][d][e] + cost);
                        }
                    }
                }
            }
        }
    }
    // rep(i, n + 1)
    // {
    //     rep(a, p + 1)
    //     {
    //         rep(b, p + 1)
    //         {
    //             rep(c, p + 1)
    //             {
    //                 rep(d, p + 1)
    //                 {
    //                     rep(e, p + 1)
    //                     {
    //                         if (dp[i][a][b][c][d][e] == 1e18)
    //                         {
    //                             continue;
    //                         }
    //                         debug(vector<int>({a, b, c, d, e}));
    //                         debug(dp[i][a][b][c][d][e]);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    ll ans = 1e18;
    rep(a, p + 1)
    {
        rep(b, p + 1)
        {
            rep(c, p + 1)
            {
                rep(d, p + 1)
                {
                    rep(e, p + 1)
                    {
                        if (dp[n][a][b][c][d][e] == 1e18)
                        {
                            continue;
                        }
                        // debug(vector<int>({a, b, c, d, e}));
                        // debug(dp[n][a][b][c][d][e]);
                        int criteria = 0;
                        if (k >= 1)
                        {
                            criteria += a == p;
                        }
                        if (k >= 2)
                        {
                            criteria += b == p;
                        }
                        if (k >= 3)
                        {
                            criteria += c == p;
                        }
                        if (k >= 4)
                        {
                            criteria += d == p;
                        }
                        if (k >= 5)
                        {
                            criteria += e == p;
                        }
                        // debug(criteria);
                        if (criteria >= k)
                        {
                            auto chmin = [](auto &a, auto b)
                            { a = min(a, b); };
                            chmin(ans, dp[n][a][b][c][d][e]);
                        }
                    }
                }
            }
        }
    }
    if (ans < 1e18)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}