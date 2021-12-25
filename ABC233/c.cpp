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
void print_map(map<S, T> mp)
{
    for (auto p : mp)
    {
        cout << "key : " << p.first << ", value : " << p.second << endl;
    }
}

int main(void)
{
    ll n, x;
    cin >> n >> x;
    map<ll, ll> mp;
    mp[1] = 1;
    rep(i, n)
    {
        ll L;
        cin >> L;
        map<ll, ll> tmp;
        rep(j, L)
        {
            ll a;
            cin >> a;
            for (auto p : mp)
            {
                if (p.first > x / a)
                {
                    continue;
                }
                tmp[p.first * a] += p.second;
            }
        }
        mp = tmp;
    }
    cout << mp[x] << endl;
}