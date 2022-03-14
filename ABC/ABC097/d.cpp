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

#include <atcoder/dsu>
using namespace atcoder;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    rep1(i, n)
    {
        cin >> p[i];
    }
    dsu uf(n + 1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        uf.merge(p[x], p[y]);
    }
    int ans = 0;
    rep1(i, n)
    {
        ans += uf.same(p[i], i);
    }
    cout << ans << endl;
}