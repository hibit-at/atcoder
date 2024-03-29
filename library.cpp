#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

ll const mod = (ll)1e9 + 7;
ll const inf = (ll)2e9;

struct UnionFind
{
    vector<int> par;

    UnionFind(int N) : par(N)
    {
        for (int i = 0; i < N; i++)
            par[i] = -1;
    }

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (same(x, y))
        {
            return;
        }
        if (par[rx] > par[ry])
            swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) { return -par[root(x)]; }
};

void YesNo(bool b)
{
    if (b)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int inf_to_minus(int n)
{
    if (n == inf)
    {
        return -1;
    }
    return n;
}

char inf_to_wall(int n)
{
    if (n == inf)
    {
        return '#';
    }
    return n + '0';
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

void chminque(int now, int next, int cost, vector<int> &dist, queue<int> &q)
{
    if (dist[now] + cost < dist[next])
    {
        dist[next] = dist[now] + 1;
        q.push(next);
    }
    return;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int index(vector<int> v, int target)
{
    return find(all(v), target) - v.begin();
}

void plus_mod(ll &a, ll b, ll mod)
{
    a += b;
    a %= mod;
}

void sub_mod(int &a, int b, int mod)
{
    a -= b;
    a %= mod;
    a += mod;
    a %= mod;
}

bool top_sort(int n, vector<vector<int>> to)
{
    vector<int> graph(n + 1);
    rep1(i, n)
    {
        for (int next : to[i])
        {
            graph[next]++;
        }
    }
    stack<int> st;
    rep1(i, n)
    {
        if (graph[i] == 0)
        {
            st.push(i);
        }
    }
    while (st.size() > 0)
    {
        int now = st.top();
        st.pop();
        for (int next : to[now])
        {
            graph[next]--;
            if (graph[next] == 0)
            {
                st.push(next);
            }
        }
    }
    rep1(i, n)
    {
        if (graph[i] > 0)
        {
            return false;
        }
    }
    return true;
}

// void tree_dp(int pos, int pre)
// {
//                 dp[pos] = 1;
//                 for (int next : to[pos])
//                 {
//                                 if (next == pre)
//                                 {
//                                                 continue;
//                                 }
//                                 tree_dp(next, pos);
//                                 dp[pos] += dp[next];
//                 }
// }

struct Edge
{
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long inf = 1LL << 60;
void dijkstra(const Graph &G, int s, vector<long long> &dis)
{
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq; // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first)
        { // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v])
        {
            if (dis[e.to] > dis[v] + e.cost)
            { // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

vector<vector<int>> bfs_grid(vector<vector<char>> maze, int sh, int sw)
{
    const int inf = 1e9;
    int h = maze.size();
    int w = maze[0].size();
    vector<vector<int>> dist(h, vector<int>(w, inf));
    vector<int> dh = {1, -1, 0, 0};
    vector<int> dw = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    q.push({sh, sw});
    dist[sh][sw] = 0;
    while (q.size() > 0)
    {
        auto now = q.front();
        q.pop();
        int now_h = now.first;
        int now_w = now.second;
        rep(i, 4)
        {
            int next_h = now_h + dh[i];
            int next_w = now_w + dw[i];
            if (next_h < 0 || h <= next_h)
            {
                continue;
            }
            if (next_w < 0 || w <= next_w)
            {
                continue;
            }
            if (maze[next_h][next_w] == '#')
            {
                continue;
            }
            if (dist[next_h][next_w] <= dist[now_h][now_w] + 1)
            {
                continue;
            }
            dist[next_h][next_w] = dist[now_h][now_w] + 1;
            q.push({next_h, next_w});
        }
    }
    return dist;
}

template <typename T>
vector<T> bfs_with_cost(int n, vector<vector<pair<int, T>>> to, int start)
{
    vector<T> dist(n + 1, inf);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        for (auto next_pair : to[now])
        {
            int next = next_pair.first;
            T cost = next_pair.second;
            if (dist[next] <= dist[now] + cost)
            {
                continue;
            }
            dist[next] = dist[now] + cost;
            q.push(next);
        }
    }
    return dist;
}

vector<int> bfs(int n, vector<vector<int>> to, int start)
{
    vector<int> dist(n + 1, inf);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        for (int next : to[now])
        {
            if (dist[next] <= dist[now] + 1)
            {
                continue;
            }
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
    return dist;
}

vector<ll> divisor(ll n)
{
    vector<ll> ans;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i * i != n)
            {
                ans.push_back(n / i);
            }
        }
    }
    sort(all(ans));
    return ans;
}

template <typename T>
set<T> devisors(T n)
{
    set<T> ans;
    for (T i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            st.insert(i);
            st.insert(n / i);
        }
    }
    return ans;
}

vector<pair<ll, ll>> prime_factorize(ll n)
{
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll ex = 0;
            while (n % i == 0)
            {
                ex++;
                n /= i;
            }
            ans.push_back({i, ex});
        }
    }
    if (n != 1)
    {
        ans.push_back({n, 1});
    }
    return ans;
}

bool isPrime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
void print_join(vector<T> v)
{
    int n = v.size();
    rep(i, n)
    {
        cout << v[i];
        if (i < n - 1)
        {
            cout << ' ';
        }
        else
        {
            cout << endl;
        }
    }
}

void print_to_with_cost(vector<vector<pair<int, int>>> to)
{
    int n = to.size();
    rep(i, n)
    {
        cout << "from " << i << " : ";
        for (auto p : to[i])
        {
            cout << "(to " << p.first << ",cost " << p.second << ") ";
        }
        cout << endl;
    }
}

template <typename T>
void print_to(vector<vector<T>> to)
{
    int n = to.size();
    rep(i, n)
    {
        cout << "from " << i << " : to ";
        for (int next : to[i])
        {
            cout << next << ",";
        }
        cout << endl;
    }
}

template <typename T>
void print_set(set<T> st)
{
    for (int s : st)
    {
        cout << s << ",";
    }
    cout << endl;
}

template <typename S, typename T>
void print_map(map<S, T> mp)
{
    for (auto p : mp)
    {
        cout << "key : " << p.first << ", value : " << p.second << endl;
    }
}

void print_maze(vector<vector<char>> maze)
{
    int n = maze.size();
    int m = maze[0].size();
    rep(i, n)
    {
        rep(j, m) { cout << maze[i][j]; }
        cout << endl;
    }
}

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (int i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

template <typename S, typename T>
void print_vector_pair(vector<pair<S, T>> v)
{
    for (pair<S, T> i : v)
    {
        cout << "(" << i.first << "," << i.second << ")"
             << " ";
    }
    cout << endl;
}

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    return;
}

template <typename T>
void print_front(T q)
{
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        cout << now << " ";
    }
    cout << endl;
}

template <typename T>
void print_top(T q)
{
    while (q.size() > 0)
    {
        int now = q.top();
        q.pop();
        cout << now << " ";
    }
    cout << endl;
}

template <typename T, typename S>
void print_pair(pair<T, S> p)
{
    cout << "(" p.first << ", " << p.second << ")" << endl;
}

template <typename T>
vector<pair<int, T>> swapmap(map<T, int> mp)
{
    vector<pair<int, T>> vp;
    for (auto p : mp)
    {
        vp.push_back(make_pair(p.second, p.first));
    }
    return vp;
}

ll rpow(ll a, ll r, ll mod)
{
    if (r == 0)
        return 1;
    ll ans = rpow(a, r / 2, mod);
    ans *= ans;
    ans %= mod;
    if (r % 2 == 1)
        ans *= a;
    ans %= mod;
    return ans;
}

vector<ll> make_fact(int limit)
{
    vector<ll> ans(limit + 1, 1);
    rep(i, limit)
    {
        ans[i + 1] = ans[i] * (i + 1);
        ans[i + 1] %= mod;
    }
    return ans;
}

vector<bool> make_erat(int limit)
{
    vector<bool> erat(limit + 1, true);
    erat[0] = false;
    erat[1] = false;
    for (int i = 0; i * i < limit; i++)
    {
        if (erat[i])
        {
            int j = i * i;
            while (j <= limit)
            {
                erat[j] = false;
                j += i;
            }
        }
    }
    return erat;
}

string binary_expression(int n, int d)
{
    string ans = "";
    rep(i, d) { ans.push_back((n >> i & 1) + '0'); }
    return ans;
}

class segment_tree
{
private:
    int sz;
    vector<int> seg;
    vector<int> lazy;
    void push(int k)
    {
        if (k < sz)
        {
            lazy[k * 2] = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = 0;
    }
    void update(int a, int b, int x, int k, int l, int r)
    {
        push(k);
        if (r <= a || b <= l)
            return;
        if (a <= l && r <= b)
        {
            lazy[k] = x;
            push(k);
            return;
        }
        update(a, b, x, k * 2, l, (l + r) >> 1);
        update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
        seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
    }
    int range_max(int a, int b, int k, int l, int r)
    {
        push(k);
        if (r <= a || b <= l)
            return 0;
        if (a <= l && r <= b)
            return seg[k];
        int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
        int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
        return max(lc, rc);
    }

public:
    segment_tree() : sz(0), seg(), lazy(){};
    segment_tree(int N)
    {
        sz = 1;
        while (sz < N)
        {
            sz *= 2;
        }
        seg = std::vector<int>(sz * 2, 0);
        lazy = std::vector<int>(sz * 2, 0);
    }
    void update(int l, int r, int x) { update(l, r, x, 1, 0, sz); }
    int range_max(int l, int r) { return range_max(l, r, 1, 0, sz); }
};

struct Point
{
    double x = 0;
    double y = 0;

    void rotation(double angle)
    {
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x;
        y = new_y;
    }

    void rotation(int degree)
    {
        double pi = atan(1) * 4;
        double angle = double(degree) / 180 * pi;
        rotation(angle);
    }

    double norm()
    {
        return sqrt(x * x + y * y);
    }

    Point operator+(Point &other)
    {
        Point ans;
        ans.x = x + other.x;
        ans.y = y + other.y;
        return ans;
    }

    Point operator-(Point &other)
    {
        Point ans;
        ans.x = x - other.x;
        ans.y = y - other.y;
        return ans;
    }

    double operator*(Point &other)
    {
        return x * other.x + y * other.y;
    }

    double operator^(Point &other)
    {
        return x * other.y - y * other.x;
    }
};

int ccw(Point A, Point B, Point C)
{
    Point AB = B - A;
    Point AC = C - A;
    if ((AB ^ AC) > 0)
    {
        return 1;
    }
    else if ((AB ^ AC) == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

bool intersect(Point A, Point B, Point C, Point D)
{
    return (ccw(A, B, D) * ccw(A, B, C)) == -1;
}