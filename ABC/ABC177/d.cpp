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

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.merge(a,b);
    }
    int ans = 0;
    rep(i, n)
    {
        // debug(i);
        // debug(uf.size(i));
        chmax(ans, uf.size(i));
    }
    cout << ans << endl;
}