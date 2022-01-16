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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
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

int main(void)
{
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<ll> w(n);
    rep(i, n)
    {
        cin >> w[i];
    }
    rep(i, q)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0)
        {
            if (!uf.same(x, y))
            {
                ll tmp = w[uf.root(x)] + w[uf.root(y)];
                uf.unite(x, y);
                w[uf.root(x)] = tmp;
            }
        }
        if (t == 1)
        {
            cout << w[uf.root(x)] << endl;
        }
    }
}