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

ll func(int k)
{
    k--;
    ll ans = 1;
    rep(i, 30)
    {
        ans *= 3;
        if (i == k)
        {
            ans++;
        }
    }
    return ans;
}

int main(void)
{
    ll n;
    cin >> n;
    rep1(i, 30)
    {
        if (func(i) == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}