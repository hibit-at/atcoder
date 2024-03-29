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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    dsu uf(2e5 + 1);
    rep(i, n / 2)
    {
        int opposite = n - 1 - i;
        uf.merge(a[i], a[opposite]);
    }
    auto groups = uf.groups();
    int ans = 0;
    for (auto v : groups)
    {
        ans += v.size() - 1;
    }
    cout << ans << endl;
}