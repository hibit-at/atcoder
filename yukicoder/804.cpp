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

int main(void)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    auto chmax = [](auto &a, auto b)
    { a = max(a, b); };
    rep(veg, a + 1)
    {
        int meat = c * veg;
        int total = veg + meat;
        // debug(total);
        if (total <= d && meat <= b)
        {
            // cout << "ok" << endl;
            chmax(ans, veg);
        }
        else
        {
            // cout << "ng" << endl;
        }
    }
    cout << ans << endl;
}