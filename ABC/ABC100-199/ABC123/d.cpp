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

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

ll x, y, z, K;
vector<ll> a, b, c;

bool solve(ll mid)
{
    ll cnt = 0;
    rep(i, x)
    {
        rep(j, y)
        {
            rep(k, min(K, z))
            {
                if (a[i] + b[j] + c[k] < mid)
                {
                    break;
                }
                cnt++;
                if (cnt >= K)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void)
{
    cin >> x >> y >> z >> K;
    a.resize(x);
    b.resize(y);
    c.resize(z);
    rep(i, x)
    {
        cin >> a[i];
    }
    rep(i, y)
    {
        cin >> b[i];
    }
    rep(i, z)
    {
        cin >> c[i];
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    reverse(all(a));
    reverse(all(b));
    reverse(all(c));
    // nibutan
    ll ng = 1e18;
    ll ok = 0;
    while (abs(ng - ok) > 1)
    {
        ll mid = (ng + ok) / 2;
        // mid以上の数はK以上か？
        if (solve(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    ll border = ok;
    // debug(border);
    priority_queue<ll> ans;
    ll cnt = 0;
    rep(i, x)
    {
        rep(j, y)
        {
            rep(k, min(K, z))
            {
                if (a[i] + b[j] + c[k] >= border)
                {
                    ans.push(a[i] + b[j] + c[k]);
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cnt = 0;
    while (ans.size() > 0 && cnt < K)
    {
        cout << ans.top() << endl;
        ans.pop();
        cnt++;
    }
}