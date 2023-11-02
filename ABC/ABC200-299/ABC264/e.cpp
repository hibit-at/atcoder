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

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

#include <atcoder/dsu>
using namespace atcoder;

int main(void)
{
    int n, m, e;
    cin >> n >> m >> e;
    vector<pair<int, int>> grid(e);
    vector<int> used(e);
    dsu uf(n + m + 1);
    for (int i = n; i < n + m; i++)
    {
        // debug(i);
        // debug(n + m);
        uf.merge(i, n + m);
    }
    rep(i, e)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        grid[i] = {u, v};
    }
    int q;
    cin >> q;
    vector<int> qx(q);
    rep(i, q)
    {
        int x;
        cin >> x;
        x--;
        used[x] = true;
        qx[i] = x;
    }
    auto print_vector = [](auto v)
    {
        int size = v.size();
        int cnt = 1;
        for (auto i : v)
        {
            cout << i;
            if (cnt < size)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
            cnt++;
        }
    };
    reverse(all(qx));
    // print_vector(qx);
    rep(i, e)
    {
        if (used[i])
        {
            continue;
        }
        auto [u, v] = grid[i];
        // debug(u);
        // debug(v);
        uf.merge(u, v);
    }
    // debug(uf.size(n + m));
    vector<int> ans;
    rep(i, q)
    {
        ans.push_back(uf.size(n + m) - m - 1);
        int x = qx[i];
        auto [u, v] = grid[qx[i]];
        // debug(u);
        // debug(v);
        uf.merge(u, v);
    }
    reverse(all(ans));
    auto print_lines = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << endl;
        }
    };
    print_lines(ans);
}