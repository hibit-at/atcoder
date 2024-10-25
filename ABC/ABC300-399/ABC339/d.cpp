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
    int n;
    cin >> n;
    vector<vector<char>> maze(n, vector<char>(n));
    using S = vector<pair<int, int>>;
    int cnt = 0;
    S state;
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, n)
        {
            char c = s[j];
            maze[i][j] = s[j];
            if (c == 'P')
            {
                state.push_back({i, j});
            }
        }
    }
    // sort(all(state));
    using VI = vector<int>;
    using VVI = vector<VI>;
    using VVVI = vector<VVI>;
    using VVVVI = vector<VVVI>;
    using VVVVVI = vector<VVVVI>;
    VVVVI memo(n, VVVI(n, VVI(n, VI(n, -1))));
    // map<S, int> memo;
    memo[state[0].first][state[0].second][state[1].first][state[1].second] = 0;
    // debug(state);
    // debug(memo);
    // cout << maze << endl;
    queue<S> q;
    q.push(state);
    // vector<int> dx = {1,-1,0,0};
    // vector<int> dy = {0,0,1,-1};
    vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans = 1e9;
    auto chmin = [](auto &a, auto b)
    { a = min(a, b); };
    while (q.size())
    {
        pair<int, int> U = q.front()[0];
        pair<int, int> V = q.front()[1];
        q.pop();
        // debug(U);
        // debug(V);
        if (U == V)
        {
            chmin(ans, memo[U.first][U.second][V.first][V.second]);
            break;
        }
        for (auto [dx, dy] : dxy)
        {
            int U_nx = U.first + dx;
            int U_ny = U.second + dy;
            if (U_nx < 0 || n <= U_nx)
            {
                U_nx = U.first;
            }
            if (U_ny < 0 || n <= U_ny)
            {
                U_ny = U.second;
            }
            if (maze[U_nx][U_ny] == '#')
            {
                U_nx = U.first;
                U_ny = U.second;
            }
            // debug(vector<int>({U_nx, U_ny}));
            int V_nx = V.first + dx;
            int V_ny = V.second + dy;
            if (V_nx < 0 || n <= V_nx)
            {
                V_nx = V.first;
            }
            if (V_ny < 0 || n <= V_ny)
            {
                V_ny = V.second;
            }
            if (maze[V_nx][V_ny] == '#')
            {
                V_nx = V.first;
                V_ny = V.second;
            }
            // debug(vector<int>({V_nx, V_ny}));
            S next_state(2);
            next_state[0] = {U_nx, U_ny};
            next_state[1] = {V_nx, V_ny};
            // sort(all(next_state));
            // debug(next_state);
            if (memo[U_nx][U_ny][V_nx][V_ny] > -1)
            {
                continue;
            }
            memo[U_nx][U_ny][V_nx][V_ny] = memo[U.first][U.second][V.first][V.second] + 1;
            q.push(next_state);
        }
    }
    // debug(memo);
    if (ans < 1e9)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}