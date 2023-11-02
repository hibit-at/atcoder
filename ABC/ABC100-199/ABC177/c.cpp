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
using mint = modint1000000007;

int main(void)
{
    int n;
    cin >> n;
    mint sum = 0;
    mint ss = 0;
    rep(i, n)
    {
        int x;
        cin >> x;
        mint a = x;
        sum += a;
        ss += a * a;
    }
    mint ans = (sum * sum - ss) / 2;
    cout << ans.val() << endl;
}