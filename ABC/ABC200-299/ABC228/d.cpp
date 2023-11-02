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
    int n = 1 << 20;
    vector<ll> a(n, -1);
    map<int, int> interval;
    map<int, ll> mp;
    interval[n] = 0;
    int q;
    cin >> q;
    rep(i, q)
    {
        int t;
        ll x;
        cin >> t >> x;
        if (t == 1)
        {
            int h = x % n;
            auto itr = interval.upper_bound(h);
            if (itr == interval.end()) // if over
            {
                h = 0;
                itr = interval.begin();
            }
            if (itr->second <= h) // if in range
            {
                mp[h] = x;
                int L1 = itr->second;
                int R1 = h;
                int L2 = h + 1;
                int R2 = itr->first;
                interval.erase(itr);
                if (L1 != R1)
                {
                    interval[R1] = L1;
                }
                if (L2 != R2)
                {
                    interval[R2] = L2;
                }
            }
            else // if out range
            {
                mp[itr->second] = x; // set start of this range
                itr->second += 1; // increment start of this range
                if (itr->first == itr->second) // if 0-range then erase
                {
                    interval.erase(itr);
                }
            }
        }
        if (t == 2)
        {
            auto itr = mp.find(x % n);
            if (itr == mp.end())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << itr->second << endl;
            }
        }
    }
}