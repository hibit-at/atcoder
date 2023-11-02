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
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> a[i][j];
        }
    }
    rep(i1, h)
    {
        for (int i2 = i1 + 1; i2 < h; i2++)
        {
            rep(j1, w)
            {
                for (int j2 = j1 + 1; j2 < w; j2++)
                {
                    if (a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2])
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
}