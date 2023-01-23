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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> dx, dy;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (i % 2 == 0)
        {
            dx.push_back(a);
        }
        else
        {
            dy.push_back(a);
        }
    }
    // debug(dx);
    // debug(dy);
    int mx = dx.size();
    int my = dy.size();
    vector<map<int, bool>> dpx(mx + 1);
    vector<map<int, bool>> dpy(my + 1);
    dpx[0][0] = 1;
    dpy[0][0] = 1;
    rep(i, mx)
    {
        if (i == 0)
        {
            dpx[i + 1][dx[0]] = 1;
        }
        else
        {
            for (auto [key, val] : dpx[i])
            {
                dpx[i + 1][key - dx[i]] = 1;
                dpx[i + 1][key + dx[i]] = 1;
            }
        }
    }
    rep(i, my)
    {
        for (auto [key, val] : dpy[i])
        {
            dpy[i + 1][key - dy[i]] = 1;
            dpy[i + 1][key + dy[i]] = 1;
        }
    }
    // debug(dpx[mx]);@
    // debug(dpy[my]);
    if (dpx[mx][x] && dpy[my][y])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}