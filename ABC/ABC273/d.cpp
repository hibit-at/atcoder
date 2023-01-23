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
    #define int ll
    int h, w;
    cin >> h >> w;
    int rs, cs;
    cin >> rs >> cs;
    rs--;
    cs--;
    int n;
    cin >> n;
    map<int, set<int>> wall_horizontal, wall_vertical;
    rep(i, n)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        wall_horizontal[r].insert(c);
        wall_vertical[c].insert(r);
    }
    // debug(wall_horizontal);
    // debug(wall_vertical);
    int q;
    cin >> q;
    while (q--)
    {
        char d;
        int L;
        cin >> d >> L;
        if (d == 'L')
        {
            if (wall_horizontal.count(rs) == 0)
            {
                cs = max(0LL, cs - L);
            }
            else
            {
                auto itr = wall_horizontal[rs].upper_bound(cs);
                if (itr == wall_horizontal[rs].begin())
                {
                    cs = max(0LL, cs - L);
                }
                else
                {
                    cs = max(*prev(itr) + 1, cs - L);
                }
            }
        }
        if (d == 'R')
        {
            if (wall_horizontal.count(rs) == 0)
            {
                cs = min(w - 1, cs + L);
            }
            else
            {
                auto itr = wall_horizontal[rs].upper_bound(cs);
                if (itr == wall_horizontal[rs].end())
                {
                    cs = min(w - 1, cs + L);
                }
                else
                {
                    cs = min(*itr - 1, cs + L);
                }
            }
        }
        if (d == 'U')
        {
            if (wall_vertical.count(cs) == 0)
            {
                rs = max(0LL, rs - L);
            }
            else
            {
                auto itr = wall_vertical[cs].upper_bound(rs);
                if (itr == wall_vertical[cs].begin())
                {
                    rs = max(0LL, rs - L);
                }
                else
                {
                    rs = max(*prev(itr) + 1, rs - L);
                }
            }
        }
        if (d == 'D')
        {
            if (wall_vertical.count(cs) == 0)
            {
                rs = min(h - 1, rs + L);
            }
            else
            {
                auto itr = wall_vertical[cs].upper_bound(rs);
                if (itr == wall_vertical[cs].end())
                {
                    rs = min(h - 1, rs + L);
                }
                else
                {
                    rs = min(*itr - 1, rs + L);
                }
            }
        }
        vector<int> check = {rs + 1, cs + 1};
        cout << check << endl;
    }
}