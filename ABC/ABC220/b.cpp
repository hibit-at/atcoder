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
    ll k, a, b;
    cin >> k >> a >> b;
    stack<int> st;
    while (a > 0)
    {
        st.push(a % 10);
        a /= 10;
    }
    ll ak = 0;
    while (st.size() > 0)
    {
        ak *= k;
        ak += st.top();
        st.pop();
    }
    // debug(ak);
    while (b > 0)
    {
        st.push(b % 10);
        b /= 10;
    }
    ll bk = 0;
    while (st.size() > 0)
    {
        bk *= k;
        bk += st.top();
        st.pop();
    }
    // debug(bk);
    ll ans = ak * bk;
    cout << ans << endl;
}