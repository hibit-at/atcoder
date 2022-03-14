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
#define P pair<int, int>
typedef long long ll;

#include <atcoder/dsu>
using namespace atcoder;

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

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<P> to(m);
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        to[i] = {a, b};
    }
    // vector<vector<bool>> dp(n, vector<bool>(n, false));
    vector<ll> useful(m);
    reverse(all(to));
    dsu uf(n);
    rep(i, m)
    {
        P edge = to[i];
        if (uf.same(edge.first, edge.second))
        {
            continue;
        }
        useful[i] = uf.size(edge.first) * uf.size(edge.second);
        uf.merge(edge.first, edge.second);
    }
    reverse(all(useful));
    // print_vector(useful);
    ll ans = 0;
    rep(i, m)
    {
        ans += useful[i];
        cout << ans << endl;
    }
}