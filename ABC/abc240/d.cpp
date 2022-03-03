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

void prll_set(stack<pair<ll, ll>> st)
{
    while (st.size() > 0)
    {
        pair<ll, ll> now = st.top();
        st.pop();
        cout << "(" << now.first << "," << now.second << "),";
    }
    cout << endl;
}

int main(void)
{
    ll n;
    cin >> n;
    stack<pair<ll, ll>> st;
    ll ans = 0;
    rep(i, n)
    {
        ll a;
        cin >> a;
        // if empty
        if (st.size() == 0)
        {
            st.push({a, 1});
            ans++;
        }
        else
        {
            // if same
            if (st.top().first == a)
            {
                ll num = st.top().second;
                st.pop();
                st.push({a, num + 1});
                ans++;
                // erase
                if (a == num + 1)
                {
                    st.pop();
                    ans -= a;
                }
            }
            else
            {
                st.push({a, 1});
                ans++;
            }
        }
        // prll_set(st);
        cout << ans << endl;
    }
}