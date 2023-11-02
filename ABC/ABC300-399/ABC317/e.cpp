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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> maze(h, vector<char>(w));
    using VI = vector<char>;
    using VVI = vector<VI>;
    using VVVI = vector<VVI>;
    using VVVVI = vector<VVVI>;
    using VVVVVI = vector<VVVVI>;
    VVVI dp(h, VVI(w, VI(4, '.')));
    // cout << dp << endl;
    int sx = -1;
    int sy = -1;
    int gx = -1;
    int gy = -1;
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> maze[i][j];
            // v^><
            if (maze[i][j] == 'v')
            {
                dp[i][j][0] = 'v';
            }
            if (maze[i][j] == '^')
            {
                dp[i][j][1] = '^';
            }
            if (maze[i][j] == '>')
            {
                dp[i][j][2] = '>';
            }
            if (maze[i][j] == '<')
            {
                dp[i][j][3] = '<';
            }
            if (maze[i][j] == '#')
            {
                dp[i][j][0] = '#';
                dp[i][j][1] = '#';
                dp[i][j][2] = '#';
                dp[i][j][3] = '#';
            }
            if (maze[i][j] == 'S')
            {
                // maze[i][j] = '.';
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 'G')
            {
                // maze[i][j] = '.';
                gx = i;
                gy = j;
            }
        }
    }
    rep(i, h - 1)
    {
        rep(j, w)
        {
            if (dp[i][j][0] == 'v' && maze[i + 1][j] == '.')
            {
                dp[i + 1][j][0] = 'v';
            }
        }
    }
    for (int i = h - 1; i > 0; i--)
    {
        rep(j, w)
        {
            if (dp[i][j][1] == '^' && maze[i - 1][j] == '.')
            {
                dp[i - 1][j][1] = '^';
            }
        }
    }
    rep(i, h)
    {
        rep(j, w - 1)
        {
            if (dp[i][j][2] == '>' && maze[i][j + 1] == '.')
            {
                dp[i][j + 1][2] = '>';
            }
        }
    }
    rep(i, h)
    {
        for (int j = w - 1; j > 0; j--)
        {
            if (dp[i][j][3] == '<' && maze[i][j - 1] == '.')
            {
                dp[i][j - 1][3] = '<';
            }
        }
    }
    // cout << dp << endl;
    vector<vector<int>> bfs(h, vector<int>(w, 1e9));
    // debug(make_pair(sx, sy));
    // debug(make_pair(gx, gy));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    bfs[sx][sy] = 0;
    vector<vector<bool>> seen(h, vector<bool>(w));
    seen[sx][sy] = 1;
    // vector<int> dx = {1,-1,0,0};
    // vector<int> dy = {0,0,1,-1};
    vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (q.size())
    {
        auto [cx, cy] = q.front();
        q.pop();
        // debug(make_pair(cx, cy));
        for (auto [dx, dy] : dxy)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            if (nx < 0 || h <= nx)
            {
                continue;
            }
            if (ny < 0 || w <= ny)
            {
                continue;
            }
            if (seen[nx][ny])
            {
                continue;
            }
            int criteria = 0;
            rep(k, 4)
            {
                criteria += dp[nx][ny][k] == '.';
            }
            // debug(criteria);
            if (criteria == 4)
            {
                bfs[nx][ny] = bfs[cx][cy] + 1;
                seen[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    // cout << bfs << endl;
    if(bfs[gx][gy] == 1e9){
        cout << -1 << endl;
    }else{
        cout << bfs[gx][gy] << endl;
    }
}