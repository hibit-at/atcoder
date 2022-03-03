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

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

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

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

// global

int n, m;
int group_size;
vector<vector<int>> to;
vector<vector<int>> to_dag;
vector<char> graph;
vector<bool> seen;

bool fullCount(vector<char> &graph)
{
    int count = 0;
    rep1(i, n)
    {
        count += (graph[i] != '.');
    }
    return count == group_size;
}

ll dfs(int now)
{
    map<char, bool> enable;
    enable['R'] = true;
    enable['G'] = true;
    enable['B'] = true;
    for (int next : to[now])
    {
        if (graph[next] == '.')
        {
            continue;
        }
        else
        {
            enable[graph[next]] = false;
        }
    }
    ll ans = 0;
    for (auto p : enable)
    {
        if (!p.second)
        {
            continue;
        }
        graph[now] = p.first;
        print_vector(graph);
        if (fullCount(graph))
        {
            ans++;
            graph[now] = '.';
            continue;
        }
        for (int next : to_dag[now])
        {
            ans += dfs(next);
        }
        graph[now] = '.';
    }
    return ans;
}

void make_to_dag(int now)
{
    debug(now);
    seen[now] = true;
    cout << "next : ";
    for (int next : to[now])
    {
        cout << next << ',';
    }
    cout << endl;
    for (int next : to[now])
    {
        if (seen[next])
        {
            continue;
        }
        to_dag[now].push_back(next);
        cout << "edge from " << now << " to " << next << " is made!" << endl;
        make_to_dag(next);
    }
    return;
}

int main(void)
{
    cin >> n >> m;
    to.resize(n + 1, vector<int>());
    to_dag.resize(n + 1, vector<int>());
    graph.resize(n + 1, '.');
    seen.resize(n + 1, false);
    UnionFind uf(n + 1);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
        uf.unite(a, b);
    }
    set<int> roots;
    rep1(i, n)
    {
        roots.insert(uf.root(i));
    }
    ll ans = 1;
    for (int start : roots)
    {
        make_to_dag(start);
        debug(start);
        // print_vector_vector(to_dag);
        group_size = uf.size(start);
        ans *= dfs(start);
    }
    cout << ans << endl;
}