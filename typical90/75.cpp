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

vector<pair<ll, ll>> prime_factorize(ll n)
{
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll ex = 0;
            while (n % i == 0)
            {
                ex++;
                n /= i;
            }
            ans.push_back({i, ex});
        }
    }
    if (n != 1)
    {
        ans.push_back({n, 1});
    }
    return ans;
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

template <typename T>
void print_vector_pair(vector<pair<T, T>> v)
{
    for (pair<T, T> i : v)
    {
        cout << "(" << i.first << "," << i.second << ")"
             << " ";
    }
    cout << endl;
}

int main(void)
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> pf = prime_factorize(n);
    // print_vector_pair<ll>(pf);
    ll sum = 0;
    for (auto p : pf)
    {
        sum += p.second;
    }
    ll tmp = 1;
    ll ans = 0;
    while (tmp < sum)
    {
        tmp *= 2;
        ans++;
    }
    cout << ans << endl;
}