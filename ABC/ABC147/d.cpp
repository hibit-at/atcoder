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

#include <atcoder/modint>
using namespace atcoder;

int main(void)
{
    int n;
    cin >> n;
    vector<map<int, modint1000000007>> mp(60);
    modint1000000007 ans;
    modint1000000007 factor = 1;
    while (n--)
    {
        ll a;
        cin >> a;
        rep(b, 60)
        {
            mp[b][a & 1]++;
            a /= 2;
        }
    }
    rep(i, 60)
    {
        ans += mp[i][0] * mp[i][1] * factor;
        factor *= 2;
    }
    cout << ans.val() << endl;
}