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

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

#include <atcoder/scc>
using namespace atcoder;

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> x(n), c(n);
    cin >> x >> c;
    scc_graph graph(n);
    rep(i, n)
    {
        graph.add_edge(i, x[i] - 1);
    }
    vector<vector<int>> scc = graph.scc();
    ll ans = 0;
    for (auto v : scc)
    {
        if (v.size() == 1)
        {
            continue;
        }
        vector<ll> hate;
        for (ll i : v)
        {
            hate.push_back(c[i]);
        }
        auto prll_vector = [](auto v)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        };
        // prll_vector(hate);
        ans += *min_element(all(hate));
    }
    cout << ans << endl;
}