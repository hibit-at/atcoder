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

vector<ll> divisor(ll n)
{
    vector<ll> ans;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i * i != n)
            {
                ans.push_back(n / i);
            }
        }
    }
    sort(all(ans));
    return ans;
}

template <typename T>
void print_vector(vector<T> v)
{
    for (ll i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    return;
}

int main(void)
{
    ll k;
    cin >> k;
    if (k == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> div = divisor(k);
    // print_vector<ll>(div);
    int n = div.size();
    ll ans = 0;
    rep(i, n - 1)
    {
        for (int j = i; j < n - 1; j++)
        {
            ll a = div[i];
            ll b = div[j];
            if (k / a < b){
                continue;
            }
            ll prod = a*b;
            if (k % prod != 0)
            {
                continue;
            }
            if (b > k / prod)
            {
                continue;
            }
            ans++;
        }
    }
    cout << ans << endl;
}