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
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

vector<bool> make_erat(int limit)
{
    vector<bool> erat(limit+1, true);
    erat[0] = false;
    erat[1] = false;
    for (int i = 0; i * i < limit; i++)
    {
        if (erat[i])
        {
            int j = i * i;
            while (j <= limit)
            {
                erat[j] = false;
                j += i;
            }
        }
    }
    return erat;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<bool> erat = make_erat(n);
    vector<int> cnt(n + 1, 0);
    rep1(i, n)
    {
        if (!erat[i])
        {
            continue;
        }
        int pos = i;
        while (pos <= n)
        {
            cnt[pos]++;
            pos += i;
        }
    }
    int ans = 0;
    rep1(i, n)
    {
        if (cnt[i] >= k)
        {
            ans++;
        }
    }
    cout << ans << endl;
}