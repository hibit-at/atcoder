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
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> vp(n);
    rep(i, n)
    {
        ll L, R;
        cin >> L >> R;
        vp[i] = {R, L};
    }
    sort(all(vp));
    // print_vector_pair(vp);
    ll ans = 0;
    ll start = 0;
    ll end = 0;
    rep(i, n)
    {
        ll t_start = vp[i].second;
        ll t_end = vp[i].first;
        bool sub1 = t_end >= start;
        bool sub2 = end >= t_start;
        if (sub1 && sub2)
        {
            continue;
        }
        start = t_end;
        end = start + d - 1;
        ans++;
    }
    cout << ans << endl;
}