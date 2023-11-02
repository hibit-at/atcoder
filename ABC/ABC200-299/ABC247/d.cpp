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
    int q;
    cin >> q;
    deque<pair<ll, ll>> dq;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll x, c;
            cin >> x >> c;
            dq.push_back({x, c});
        }
        if (type == 2)
        {
            ll c;
            cin >> c;
            ll ans = 0;
            while (c > 0)
            {
                auto front = dq.front();
                dq.pop_front();
                ll front_c = front.second;
                ll front_x = front.first;
                // debug(front_c);
                // debug(front_x);
                if (c > front_c)
                {
                    c -= front_c;
                    ans += front_c * front_x;
                }
                else
                {
                    front_c -= c;
                    ans += c * front_x;
                    c = 0;
                    dq.push_front({front_x, front_c});
                }
            }
            cout << ans << endl;
        }
    }
}