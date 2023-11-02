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
    ll n, x;
    cin >> n >> x;
    ll inf = 1LL << 61;
    vector<ll> s(n + 1), game(n + 1, inf);
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        s[i + 1] = s[i] + a + b;
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        chmin(game[i + 1], min(game[i], b));
    }
    auto print_vector = [](auto v)
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
    // print_vector(s);
    // print_vector(game);
    ll ans = inf;
    rep1(i, n)
    {
        // debug(i);
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        // debug(s[i] + game[i] * (x - i));
        chmin(ans, s[i] + game[i] * (x - i));
    }
    cout << ans << endl;
}