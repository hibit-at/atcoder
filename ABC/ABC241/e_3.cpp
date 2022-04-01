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

#include <atcoder/scc>
using namespace atcoder;

int main(void)
{
    int n;
    ll k;
    cin >> n >> k;
    scc_graph graph(n);
    vector<int> a(n);
    vector<ll> loop(n, -1);
    vector<ll> loop_plus(n);
    rep(i, n)
    {
        int x;
        cin >> x;
        graph.add_edge(i, (i + x) % n);
        a[i] = x;
        if (i == (i + x) % n)
        {
            loop[i] = 1;
            loop_plus[i] = x;
        }
    }
    auto scc = graph.scc();
    for (auto v : scc)
    {
        if (v.size() == 1)
        {
            continue;
        }
        ll plus = 0;
        for (int i : v)
        {
            plus += a[i];
        }
        for (int i : v)
        {
            loop[i] = v.size();
            loop_plus[i] = plus;
        }
    }
    int pos = 0;
    ll ans = 0;
    while (k--)
    {
        ans += a[pos];
        pos = ans % n;
        if (loop[pos] > -1)
        {
            ans += loop_plus[pos] * (k / loop[pos]);
            k %= loop[pos];
        }
    }
    cout << ans << endl;
}