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

void trim(vector<vector<char>> &p)
{
    int h = p.size();
    int w = p[0].size();
    // debug(vector<int>({h, w}));
    int sx = 1e9;
    int sy = 1e9;
    int tx = -1;
    int ty = -1;
    rep(i, h)
    {
        rep(j, w)
        {
            if (p[i][j] == '#')
            {
                auto chmin = [](auto &a, auto b)
                { a = min(a, b); };
                auto chmax = [](auto &a, auto b)
                { a = max(a, b); };
                chmin(sx, i);
                chmin(sy, j);
                chmax(tx, i);
                chmax(ty, j);
            }
        }
    }
    // debug(vector<int>({sx, sy, tx, ty}));
    vector<vector<char>> q(tx - sx + 1, vector<char>(ty - sy + 1));
    rep(i, tx - sx + 1)
    {
        rep(j, ty - sy + 1)
        {
            q[i][j] = p[sx + i][sy + j];
        }
    }
    p = q;
}

void rot(vector<vector<char>> &p)
{
    int h = p.size();
    int w = p[0].size();
    vector<vector<char>> q(w, vector<char>(h));
    rep(i, h)
    {
        rep(j, w)
        {
            q[j][h - i - 1] = p[i][j];
        }
    }
    p = q;
}

int main()
{
    vector<vector<char>> a(4, vector<char>(4));
    vector<vector<char>> b(4, vector<char>(4));
    vector<vector<char>> c(4, vector<char>(4));
    cin >> a >> b >> c;
    trim(a);
    trim(b);
    trim(c);
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // rep(i, 4)
    // {
    //     rot(a);
    //     cout << a << endl;
    // }
    vector<pair<int, int>> pos;
    rep(i, 4)
    {
        rep(j, 4)
        {
            pos.push_back({i, j});
        }
    }
    // debug(pos);
    using VI = vector<char>;
    using VVI = vector<VI>;
    using VVVI = vector<VVI>;
    using VVVVI = vector<VVVI>;
    using VVVVVI = vector<VVVVI>;
    VVVI ra;
    VVVI rb;
    VVVI rc;
    rep(i, 4)
    {
        ra.push_back(a);
        rb.push_back(b);
        rc.push_back(c);
        rot(a);
        rot(b);
        rot(c);
    }
    for (auto [ax, ay] : pos)
    {
        for (auto [bx, by] : pos)
        {
            for (auto [cx, cy] : pos)
            {
                rep(p, 4)
                {
                    rep(q, 4)
                    {
                        rep(r, 4)
                        {
                            vector<vector<int>> canvas(8, vector<int>(8, 0));
                            int px = ra[p].size();
                            int py = ra[p][0].size();
                            rep(i, px)
                            {
                                rep(j, py)
                                {
                                    if (ra[p][i][j] == '#')
                                    {
                                        canvas[ax + i][ay + j]++;
                                    }
                                }
                            }
                            int qx = rb[q].size();
                            int qy = rb[q][0].size();
                            rep(i, qx)
                            {
                                rep(j, qy)
                                {
                                    if (rb[q][i][j] == '#')
                                    {
                                        canvas[bx + i][by + j]++;
                                    }
                                }
                            }
                            int rx = rc[r].size();
                            int ry = rc[r][0].size();
                            rep(i, rx)
                            {
                                rep(j, ry)
                                {
                                    if (rc[r][i][j] == '#')
                                    {
                                        canvas[cx + i][cy + j]++;
                                    }
                                }
                            }
                            // cout << canvas << endl;
                            int criteria = 0;
                            rep(i, 8)
                            {
                                rep(j, 8)
                                {
                                    if (i < 4 && j < 4)
                                    {
                                        criteria += canvas[i][j] == 1;
                                    }
                                    else
                                    {
                                        criteria += canvas[i][j] == 0;
                                    }
                                }
                            }
                            if (criteria == 64)
                            {
                                // debug(vector<int>({ax, ay, bx, by, cx, cy, p, q, r}));
                                // cout << ra[p] << endl;
                                // cout << rb[q] << endl;
                                // cout << rc[r] << endl;
                                // cout << canvas << endl;
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}