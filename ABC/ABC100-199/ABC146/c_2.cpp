#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

ll d(ll n) {
    ll ans = 0;
    while (n > 0) {
        ans++;
        n /= 10;
    }
    return ans;
}

int main(void) {
    ll a, b, x;
    cin >> a >> b >> x;
    ll ok = -1;      // step3 で追加。リストでok側になってる方
    ll ng = 1e9 + 1; // step3 で追加。リストでng側になってる方
    while (abs(ok - ng) > 1) // step3 で追加
    // rep(target, 20) // step2 で追加。step3 でコメントアウト。
    {
        // ll target = 9; step2 でコメントアウト
        ll target = (ok + ng) / 2;
        ll price = a * target + b * d(target);
        // cout << price << endl; step2 でコメントアウト
        if (price <= x) {
            // cout << target << " ok" << endl;
            ok = target; // step3 で追加
        } else {
            // cout << target << " ng" << endl;
            ng = target; // step3 で追加
        }
    }
    cout << ok << endl;
}