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
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> dec(0);
    rep1(i, 1e5)
    {
        if (i == 1)
        {
            continue;
        }
        ll pos = ll(i) * i;
        if (pos < 0)
        {
            debug(pos);
        }
        dec.push_back(pos);
        while (pos <= 1e10)
        {
            // debug(pos);
            pos *= i;
            if (pos > 1e10)
            {
                break;
            }
            dec.push_back(pos);
        }
    }
    sort(all(dec));
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    dec.erase(unique(all(dec)), dec.end());
    // print_vec@tor(dec);
    auto itr = upper_bound(all(dec), n);
    itr--;
    int where = itr - dec.begin() + 1;
    // debug(where);
    // debug(*it@r);
    cout << n - where << endl;
}