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

// utils

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

string binary_expression(int n, int d)
{
    string ans = "";
    rep(i, d) { ans.push_back((n >> i & 1) + '0'); }
    return ans;
}

// global

int n, m;
vector<pair<int, int>> edge;

// function

ll func(int bit)
{
    // is red connected?
    ll ans = 1;
    rep(i, m)
    {
        bool flag1 = (bit >> edge[i].first) & 1;
        bool flag2 = (bit >> edge[i].second) & 1;
        bool bothRed = flag1 & flag2;
        if (bothRed)
        {
            return 0;
        }
    }
    // is binary graph?
    UnionFind uf(n * 2);
    rep(i, m)
    {
        bool flag1 = (bit >> edge[i].first) & 1;
        bool flag2 = (bit >> edge[i].second) & 1;
        bool anyRed = flag1 | flag2;
        if (anyRed)
        {
            continue;
        }
        uf.unite(edge[i].first, edge[i].second + n);
        uf.unite(edge[i].first + n, edge[i].second);
    }
    rep(i, n)
    {
        if (uf.same(i, n + i))
        {
            return 0;
        }
    }
    // how many groups?
    rep(i, n)
    {
        bool isRed = (bit >> i) & 1;
        if (!isRed)
        {
            if (uf.root(i) == i)
            {
                ans *= 2;
            }
        }
    }
    return ans;
}

// main

int main(void)
{
    cin >> n >> m;
    edge.resize(m);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[i] = {a, b};
    }
    ll ans = 0;
    rep(bit, 1 << n)
    {
        ans += func(bit);
    }
    cout << ans << endl;
}