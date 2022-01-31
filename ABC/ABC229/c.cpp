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

template <typename S, typename T>
void print_vector_pair(vector<pair<S, T>> v)
{
    for (pair<S, T> i : v)
    {
        cout << "(" << i.first << "," << i.second << ")"
             << " ";
    }
    cout << endl;
}

int main(void)
{
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> vp(n);
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        vp[i] = {a, b};
    }
    sort(all(vp));
    reverse(all(vp));
    // print_vector_pair<ll, ll>(vp);
    ll ans = 0;
    for (auto p : vp)
    {
        ll value = p.first;
        ll stock = p.second;
        ll valid_stock = min(w, stock);
        ans += valid_stock * value;
        w -= valid_stock;
        if (w == 0)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}