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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main()
{
    ll x;
    cin >> x;
    ll a, cnt;
    ll ans = 0;
    cin >> a;
    cnt = min(x/50,a);
    x -= cnt*50;
    ans += cnt;
    cin >> a;
    cnt = min(x/10,a);
    x -= cnt*10;
    ans += cnt;
    cin >> a;
    cnt = min(x/5,a);
    x -= cnt*5;
    ans += cnt;
    cin >> a;
    cnt = min(x,a);
    x -= cnt;
    ans += cnt;
    cout << ans << endl;
}