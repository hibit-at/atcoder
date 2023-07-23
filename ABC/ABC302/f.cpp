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

#include <atcoder/dsu>
using namespace atcoder;

int main()
{
    int n, m;
    cin >> n >> m;
    int lim = 2e5+10;
    vector<vector<int>> to(n + lim, vector<int>());
    vector<bool> contains_1(n);
    rep(i, n)
    {
        int a;
        cin >> a;
        rep(j, a)
        {
            int s;
            cin >> s;
            s--;
            // debug(s);
            to[i].push_back(n + s);
            to[n + s].push_back(i);
            if (s == 0)
            {
                contains_1[i] = 1;
            }
        }
    }
    // debug(to);
    int inf = 1e9;
    vector<int> dist(n + lim, inf);
    dist[n - 1] = 0;
    int ans = 1e9;
    queue<int> q;
    q.push(n - 1);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        // debug(now);
        if (now < n)
        {
            if (contains_1[now])
            {
                auto chmin = [](auto &a, auto b)
                { a = min(a, b); };
                chmin(ans, dist[now]);
            }
        }
        for (int next : to[now])
        {
            // debug(next);
            if (dist[next] <= dist[now] + 1)
            {
                continue;
            }
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
    // debug(contains_1);
    // debug(dist);
    // debug(ans);
    if (ans == inf)
    {
        cout << -1 << endl;
    }else{
        cout << ans/2 << endl;
    }
}