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

vector<vector<char>> trim(vector<vector<char>> walk)
{
    int min_x = 1e9;
    int max_x = -1e9;
    int min_y = 1e9;
    int max_y = -1e9;
    int h = walk.size();
    int w = walk[0].size();
    rep(i, h)
    {
        rep(j, w)
        {
            auto chmin = [](auto &a, auto b)
            { a = min(a, b); };
            auto chmax = [](auto &a, auto b)
            { a = max(a, b); };
            if (walk[i][j] == '.')
            {
                chmin(min_x, i);
                chmin(min_y, j);
                chmax(max_x, i);
                chmax(max_y, j);
            }
        }
    }
    vector<vector<char>> ans;
    for (int i = min_x; i <= max_x; i++)
    {
        vector<char> tmp;
        for (int j = min_y; j <= max_y; j++)
        {
            tmp.push_back(walk[i][j]);
        }
        ans.push_back(tmp);
    }
    return ans;
}

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    int lim = 1001;
    vector<vector<char>> walk(lim, vector<char>(lim, '?'));
    int cx = lim / 2;
    int cy = lim / 2;
    walk[cx][cy] = '.';
    rep(i, n)
    {
        char c;
        cin >> c;
        if (c == 'D')
        {
            cx++;
        }
        if (c == 'U')
        {
            cx--;
        }
        if (c == 'R')
        {
            cy++;
        }
        if (c == 'L')
        {
            cy--;
        }
        walk[cx][cy] = '.';
    }
    // cout << walk << endl;
    vector<vector<char>> valid = trim(walk);
    // cout << valid << endl;
    int p = valid.size();
    int q = valid[0].size();
    vector<vector<char>> maze(h, vector<char>(w));
    cin >> maze;
    // debug(vector<int>({p, q}));
    // cout << maze << endl;
    int ans = 0;
    rep(i, h)
    {
        if (i == 0)
        {
            continue;
        }
        if (i + p >= h)
        {
            continue;
        }
        rep(j, w)
        {
            if (j == 0)
            {
                continue;
            }
            if (j + q >= w)
            {
                continue;
            }
            // debug(vector<int>({i, j}));
            bool okay = true;
            rep(dp, p)
            {
                rep(dq, q)
                {
                    if (valid[dp][dq] == '?')
                    {
                        continue;
                    }
                    else if (maze[i + dp][j + dq] == '#')
                    {
                        okay = false;
                        break;
                    }
                }
                if(!okay){
                    break;
                }
            }
            ans += okay;
        }
    }
    cout << ans << endl;
}