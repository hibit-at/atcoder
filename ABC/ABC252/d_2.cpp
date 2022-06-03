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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    ll ans = 0;
    for(int i : a)
    {
        ll less_than_me = lower_bound(all(a), i) - a.begin();
        ll more_than_me = a.end() - upper_bound(all(a), i);
        ans += less_than_me * more_than_me;
    }
    cout << ans << endl;
}