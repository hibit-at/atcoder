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

int main()
{
    int n;
    cin >> n;
    // vector<vector<int>> to(n, vector<int>());
    vector<set<int>> to(n);
    vector<int> node(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        to[u].insert(v);
        to[v].insert(u);
        node[u]++;
        node[v]++;
    }
    // debug(to);
    // debug(node);
    queue<int> q;
    rep(i, n)
    {
        if (node[i] == 1)
        {
            q.push(i);
        }
    }
    // debug(q);
    vector<int> weight(n);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        node[now]--;
        for (int next : to[now])
        {
            // debug(next);
            node[next]--;
            to[next].erase(now);
            weight[next]++;
        }
        to[now] = {};
    }
    rep(i, n)
    {
        if (weight[i] == n - 1)
        {
            cout << n - 1 << endl;
            return 0;
        }
    }
    // debug(node);
    // debug(weight);   
    // debug(to);
    vector<int> dist(n, -1);
    vector<int> ans;
    rep(i, n)
    {
        if (node[i] == 1)
        {
            dist[i] = 0;
            q.push(i);
            break;
        }
    }
    // debug(q);
    // debug(dist);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        // debug(now);
        weight[now] += to[now].size();
        // debug(to[now]);
        if (dist[now] % 3 == 0)
        {
            ans.push_back(weight[now]);
        }
        for (int next : to[now])
        {
            dist[next] = dist[now] + 1;
            weight[next]++;
            to[next].erase(now);
            q.push(next);
        }
        to[now] = {};
    }
    // debug(dist);
    sort(all(ans));
    cout << ans << endl;
}