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

int N; ll A[301010];
//---------------------------------------------------------------------------------------------------
int main()
{
    cin >> N;
    rep(i, N) cin >> A[i];

    modint1000000007 ans = 0;
    rep(b, 60)
    {
        ll msk = 1LL << b;

        int zero = 0, one = 0;
        rep(i, N)
        {
            if (A[i] & msk)
                one++;
            else
                zero++;
        }

        ans += modint1000000007(msk) * zero * one;
    }
    cout << ans.val() << endl;
    return 0;
}