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

#include <atcoder/maxflow>
using namespace atcoder;

int main()
{
    int n;
    cin >> n;
    mf_graph<ll> graph(2 * n + 2);
    rep1(i, n + 1)
    {
        ll a;
        cin >> a;
        graph.add_edge(i, n + i, a);
        if (i > 1)
        {
            graph.add_edge(i - 1, n + i, a);
        }
        graph.add_edge(n + i, 2 * n + 1, a);
    }
    rep1(i, n)
    {
        ll b;
        cin >> b;
        graph.add_edge(0, i, b);
    }
    cout << graph.flow(0, 2 * n + 1) << endl;
    // TLE!!
}