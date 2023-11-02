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
#include <atcoder/modint>
using namespace atcoder;
using mint = modint;

int main(void)
{
    int n, a;
    cin >> n >> a;
    a--;
    string k;
    cin >> k;
    scc_graph graph(n);
    vector<int> b(n);
    rep(i, n)
    {
        cin >> b[i];
        b[i]--;
        graph.add_edge(i, b[i]);
    }
    int m = k.size();
    if (m <= 6)
    {
        ll ktoll = stoll(k);
        int pos = a;
        while (ktoll--)
        {
            pos = b[pos];
        }
        cout << pos + 1 << endl;
        return 0;
    }
    auto scc = graph.scc();
    vector<int> loops(n);
    for (auto v : scc)
    {
        for (auto i : v)
        {
            loops[i] = v.size();
        }
    }
    int pos = a;
    int branch = 0;
    while (loops[pos] == 1)
    {
        pos = b[pos];
        branch++;
    }
    int loop_size = loops[pos];
    mint::set_mod(loop_size);
    vector<mint> factor(m, 1);
    rep(i, m - 1)
    {
        factor[i + 1] = factor[i] * 10;
    }
    reverse(all(k));
    mint final_path = 0;
    rep(i, m)
    {
        final_path += int(k[i] - '0') * factor[i];
    }
    while (branch % loop_size != final_path.val())
    {
        branch++;
        pos = b[pos];
    }
    cout << pos + 1 << endl;
}