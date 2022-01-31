#include <algorithm>
#include <iostream>
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> vv(n, vector<ll>(m));
    rep(i, n)
    {
        rep(j, m)
        {
            ll b;
            cin >> b;
            b--;
            vv[i][j] = b;
            // debug(vv[i][j]);
            if (j > 0)
            {
                if (vv[i][j - 1] != vv[i][j] - 1)
                {
                    cout << "No" << endl;
                    return 0;
                }
                if (vv[i][j - 1] % 7 != vv[i][j] % 7 - 1)
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
            if (i > 0)
            {
                if (vv[i - 1][j] != vv[i][j] - 7)
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}