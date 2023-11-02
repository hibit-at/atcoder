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

struct BIT
{
    int n;
    vector<ll> node;

    // BIT(ll n) : n(n), a(n + 1, 0) {}

    BIT(vector<ll> a)
    {
        n = a.size();
        node.resize(n + 1);
        rep(i, n)
        {
            add(i, a[i]);
        }
    }

    void add(int i, ll x)
    {
        i++;
        if (i == 0)
        {
            return;
        }
        for (int k = i; k <= n; k += (k & -k))
        {
            node[k] += x;
        }
    }

    ll sum(int i, int j)
    {
        return sum_sub(j) - sum_sub(i - 1);
    }

    ll sum_sub(int i)
    {
        i++;
        ll s = 0;
        if (i == 0)
        {
            return s;
        }
        for (ll k = i; k > 0; k -= (k & -k))
        {
            s += node[k];
        }
        return s;
    }
};

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

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    BIT bit(a);
    print_vector(bit.node);
    ll ans = 0;
    rep(i, k)
    {
        ans += bit.sum(i, n - 1 - i);
    }
    cout << ans << endl;
}