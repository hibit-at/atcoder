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

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    return;
}

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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), sum(n + 1);
    map<ll, ll> mp;
    rep(i, n)
    {
        cin >> a[i];
    }
    rep1(i, n)
    {
        sum[i] = a[i - 1];
        if (i > 1)
        {
            sum[i] += sum[i - 1];
        }
    }
    // print_vector(sum);
    // print_map(mp);
    ll ans = 0;
    rep(i, n)
    {
        mp[sum[i]]++;
        ans += mp[sum[i+1] - k];
    }
    cout << ans << endl;
}