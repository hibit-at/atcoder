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

int main(void)
{
    int n;
    cin >> n;
    mf_graph<int> graph(2 * n + 2);
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    rep(i, n)
    {
        cin >> c[i] >> d[i];
    }
    rep(i, n)
    {
        rep(j, n)
        {
            bool sub1 = a[i] < c[j];
            bool sub2 = b[i] < d[j];
            if (sub1 && sub2)
            {
                graph.add_edge(i, n + j, 1);
            }
        }
    }
    rep(i, n)
    {
        graph.add_edge(2 * n, i, 1);
    }
    rep(i, n)
    {
        graph.add_edge(n + i, 2 * n + 1, 1);
    }
    int ans = graph.flow(2 * n, 2 * n + 1);
    cout << ans << endl;
}