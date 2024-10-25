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
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> maze(h, vector<char>(w));
    cin >> maze;
    // cout << maze << endl;
    vector<vector<int>> o_sum(h + 1, vector<int>(w + 1));
    vector<vector<int>> x_sum(h + 1, vector<int>(w + 1));
    rep(i, h)
    {
        rep(j, w)
        {
            o_sum[i+1][j+1] = o_sum[i+1][j] + (maze[i][j] == '.');
            x_sum[i+1][j+1] = x_sum[i+1][j] + (maze[i][j] == 'x');
        }
    }
    rep(i,h){
        rep(j,w){
            o_sum[i+1][j+1] += o_sum[i][j+1];
            x_sum[i+1][j+1] += x_sum[i][j+1];
        }
    }
    // debug(o_sum);
    // debug(x_sum);
    int ans = 1e9;
    rep(i, h)
    {
        rep(j, w - k + 1)
        {
            int o_cnt = o_sum[i+1][j+k] + o_sum[i][j] - o_sum[i][j+k] - o_sum[i+1][j];
            // debug(o_cnt);
            int x_cnt = x_sum[i+1][j+k] + x_sum[i][j] - x_sum[i][j+k] - x_sum[i+1][j];
            // debug(x_cnt);
            if(x_cnt == 0){
                auto chmin = [](auto &a, auto b)
                { a = min(a, b); };
                chmin(ans, o_cnt);
            }
        }
    }
    rep(i, h - k + 1)
    {
        rep(j, w)
        {
            int o_cnt = o_sum[i+k][j+1] + o_sum[i][j] - o_sum[i+k][j] - o_sum[i][j+1];
            int x_cnt = x_sum[i+k][j+1] + x_sum[i][j] - x_sum[i+k][j] - x_sum[i][j+1];
            if(x_cnt == 0){
                auto chmin = [](auto &a, auto b)
                { a = min(a, b); };
                chmin(ans, o_cnt);
            }
        }
    }
    if (ans < 1e9)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}