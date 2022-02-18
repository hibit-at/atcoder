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
    ll k;
    cin >> n >> k;
    map<int, ll> mp;
    rep(i, n)
    {
        int a;
        ll b;
        cin >> a >> b;
        mp[a] += b;
    }
    vector<ll> sum;
    for (auto p : mp)
    {
        if (sum.size() == 0)
        {
            sum.push_back(p.second);
            continue;
        }
        sum.push_back(sum.back() + p.second);
    }
    auto where = lower_bound(all(sum), k) - sum.begin();
    auto pos = mp.begin();
    rep(i, where)
    {
        pos++;
    }
    cout << pos->first << endl;
}