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
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    int ans = 0;
    rep(i, n)
    {
        if (a[i] < p)
        {
            ans++;
        }
    }
    cout << ans << endl;
}