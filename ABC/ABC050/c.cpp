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
    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    modint1000000007 ans = 1;
    if (n % 2 == 1)
    {
        rep(i, n / 2 + 1)
        {
            if (i == 0)
            {
                if (mp[i] != 1)
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
            else
            {
                if (mp[i] != 2)
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
            i++;
        }
        int r = n / 2;
        while (r--)
        {
            ans *= 2;
        }
        cout << ans.val() << endl;
    }
    else
    {
        rep(i, n / 2)
        {
            if (mp[i + 1] != 2)
            {
                cout << 0 << endl;
                return 0;
            }
            i++;
        }
        int r = n / 2;
        while (r--)
        {
            ans *= 2;
        }
        cout << ans.val() << endl;
    }
}