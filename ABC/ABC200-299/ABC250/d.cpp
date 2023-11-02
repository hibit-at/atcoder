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

vector<bool> make_erat(int limit)
{
    vector<bool> erat(limit + 1, true);
    erat[0] = false;
    erat[1] = false;
    for (int i = 0; i * i < limit; i++)
    {
        if (erat[i])
        {
            int j = i * i;
            while (j <= limit)
            {
                erat[j] = false;
                j += i;
            }
        }
    }
    return erat;
}

int main(void)
{
    ll n;
    cin >> n;
    vector<bool> erat = make_erat(1e6);
    vector<ll> primes(0);
    rep(i, 1e6)
    {
        if (erat[i])
        {
            primes.push_back(i);
        }
    }
    auto print_join = [](auto v)
    {
        int size = v.size();
        rep(i, size)
        {
            if (i < size - 1)
            {
                cout << v[i] << ' ';
            }
            else
            {
                cout << v[i] << endl;
            }
        }
    };
    int size = primes.size();
    ll ans = 0;
    for (int i = 0; i < size; i++)
    {
        ll p = primes[i];
        if (p > n / p / p / p)
        {
            break;
        }
        for (int j = i + 1; j < size; j++)
        {
            ll q = primes[j];
            if (p > n / q / q / q)
            {
                break;
            }
            ans++;
        }
    }
    cout << ans << endl;
}