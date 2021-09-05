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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

int main(void)
{
    ll l, q;
    cin >> l >> q;
    vector<ll> v = {0, l};
    rep(_, q)
    {
        ll c, x;
        cin >> c >> x;
        if (c == 1)
        {
            v.push_back(x);
            sort(all(v));
        }
        if (c == 2)
        {
            auto lb = lower_bound(all(v),x);
            ll start = *(lb-1);
            ll end = *lb;
            cout << end - start << endl;
        }
    }
}