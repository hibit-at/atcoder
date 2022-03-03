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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<ll> dx = {-2, -1, 1, 2, -2, -1, 1, 2};
    vector<ll> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    map<pair<ll, ll>, bool> mp;
    rep(i, 8)
    {
        ll x = x1 + dx[i];
        ll y = y1 + dy[i];
        mp[{x, y}] = true;
    }
    rep(i, 8)
    {
        ll x = x2 + dx[i];
        ll y = y2 + dy[i];
        if (mp[{x, y}])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}