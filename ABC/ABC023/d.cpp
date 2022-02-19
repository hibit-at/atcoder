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

// utils

typedef long long ll;
const ll inf = 1e18;

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

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

// global variants

int n;
vector<ll> h, s;

bool solve(ll target)
{
    vector<ll> life(n);
    rep(i, n)
    {
        if (target - h[i] < 0)
        {
            return false;
        }
        life[i] = (target - h[i]) / s[i];
    }
    sort(all(life));
    // print_vector(life);
    int size = life.size();
    rep(i, size)
    {
        if (life[i] < i)
        {
            return false;
        }
    }
    return true;
}

// main

int main(void)
{
    cin >> n;
    h.resize(n);
    s.resize(n);
    rep(i, n)
    {
        cin >> h[i] >> s[i];
    }
    // print_vector(h);
    // print_vector(s);
    ll ng = 0;
    ll ok = 1e18;
    while (abs(ng - ok) > 1)
    {
        ll mid = ng + ok;
        mid /= 2;
        if (solve(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}