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

int n, h, w;
vector<int> use;
vector<pair<int, int>> AB;

int dfs(int pos, vector<vector<int>> state, vector<pair<int, int>> valid)
{
    if (pos == valid.size())
    {
        int check = 0;
        rep(i, h)
        {
            rep(j, w)
            {
                check += state[i][j];
            }
        }
        return check == h * w;
    }
    auto [a, b] = valid[pos];
    int ans = 0;
    auto chmax = [](auto &a, auto b)
    { a = max(a, b); };
    rep(idx, h * w)
    {
        int i = idx / w;
        int j = idx % w;
        if (state[i][j])
        {
            continue;
        }
        if (i + a <= h && j + b <= w)
        {
            vector<vector<int>> next_state = state;
            rep(p, a)
            {
                rep(q, b)
                {
                    next_state[i + p][j + q] = 1;
                }
            }
            chmax(ans, dfs(pos + 1, next_state, valid));
        }
        break;
    }
    rep(idx, h * w)
    {
        int i = idx / w;
        int j = idx % w;
        if (state[i][j])
        {
            continue;
        }
        if (i + b <= h && j + a <= w)
        {
            vector<vector<int>> next_state = state;
            rep(p, b)
            {
                rep(q, a)
                {
                    next_state[i + p][j + q] = 1;
                }
            }
            chmax(ans, dfs(pos + 1, next_state, valid));
        }
        break;
    }
    return ans;
}

int main()
{
    cin >> n >> h >> w;
    AB.resize(n);
    cin >> AB;
    use.resize(n);
    rep(i, 1 << n)
    {
        int area = 0;
        rep(j, n)
        {
            if (i >> j & 1)
            {
                area += AB[j].first * AB[j].second;
            }
        }
        // debug(area);
        if (area != h * w)
        {
            continue;
        }
        vector<pair<int, int>> valid_AB;
        rep(j, n)
        {
            use[j] = (i >> j) & 1;
            if (use[j])
            {
                valid_AB.push_back(AB[j]);
            }
        }
        sort(all(valid_AB));
        vector<vector<int>> init(h, vector<int>(w, 0));
        do
        {
            // debug(valid_AB);
            int res = dfs(0, init, valid_AB);
            // debug(res);
            if (res)
            {
                cout << "Yes" << endl;
                return 0;
            }
        } while (next_permutation(all(valid_AB)));
    }
    cout << "No" << endl;
}