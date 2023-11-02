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

const ll inf = 1e18;

template <typename T>
void print_vector(vector<T> v)
{
    for (ll i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    return;
}

ll rpow(ll a, ll r, ll mod)
{
    if (r == 0)
        return 1;
    ll ans = rpow(a, r / 2, mod);
    ans *= ans;
    ans %= mod;
    if (r % 2 == 1)
        ans *= a;
    ans %= mod;
    return ans;
}

void use_check(vector<ll> &avail, vector<ll> &player, string s)
{
    s.pop_back();
    for (char c : s)
    {
        avail[c - '0']--;
        player[c - '0']++;
    }
    s.push_back('#');
    return;
}

ll calc_score(vector<ll> &player)
{
    ll ans = 0;
    rep1(i, 9)
    {
        ans += i * rpow(10, player[i], inf);
    }
    return ans;
}

int main()
{
    ll k;
    string s, t;
    cin >> k >> s >> t;
    vector<ll> avail(10, 0);
    rep1(i, 9)
    {
        avail[i] = k;
    }
    vector<ll> takahashi(10, 0);
    vector<ll> aoki(10, 0);
    use_check(avail, takahashi, s);
    use_check(avail, aoki, t);
    ll win_cases = 0;
    rep1(i, 9)
    {
        if (avail[i] == 0)
        {
            continue;
        }
        ll cases = 1;
        cases *= avail[i];
        avail[i]--;
        rep1(j, 9)
        {
            if (avail[j] == 0)
            {
                continue;
            }
            cases *= avail[j];
            takahashi[i]++;
            aoki[j]++;
            ll takahashi_score = calc_score(takahashi);
            ll aoki_score = calc_score(aoki);
            if (takahashi_score > aoki_score)
            {
                win_cases += cases;
            }
            takahashi[i]--;
            aoki[j]--;
            cases /= avail[j];
        }
        avail[i]++;
        cases /= avail[i];
    }
    ll all_cases = (9 * k - 8) * (9 * k - 9);
    cout << setprecision(20) << (double)win_cases / all_cases << endl;
}