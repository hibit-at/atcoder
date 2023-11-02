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

int n, m;
string now;
vector<string> ans;
set<string> st;
vector<int> used;
vector<string> s;

void dfs()
{
    if (ans.size())
    {
        return;
    }
    // debug(now);
    int sz = now.size();
    if (sz > 16)
    {
        return;
    }
    if (3 <= now.size() && now.size() <= 16)
    {
        int used_check = accumulate(all(used), 0);
        if (st.count(now) == 0 && now.back() != '_' && used_check == n)
        {
            // debug("ok");
            ans.push_back(now);
            return;
        }
    }
    now.push_back('_');
    dfs();
    now.pop_back();
    if (now.back() == '_')
    {
        rep(i, n)
        {
            if (used[i])
            {
                continue;
            }
            int next_sz = s[i].size();
            if (sz + next_sz <= 16)
            {
                for (char c : s[i])
                {
                    now.push_back(c);
                }
                used[i] = true;
                dfs();
                used[i] = false;
                rep(j, next_sz)
                {
                    now.pop_back();
                }
            }
        }
    }
}

int main()
{
    // int n, m;
    cin >> n >> m;
    s.resize(n);
    used.resize(n);
    cin >> s;
    rep(i, m)
    {
        string t;
        cin >> t;
        st.insert(t);
    }
    // debug(s);
    // debug(st);
    rep(i, n)
    {
        now = s[i];
        used[i] = true;
        dfs();
        used[i] = false;
        now = "";
    }
    if (ans.size())
    {
        cout << ans[0] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}