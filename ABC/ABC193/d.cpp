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

int k;
string s, t;
vector<double> leftover;
vector<ll> hand_taka;
vector<ll> hand_aoki;
double hand;
const ll mod = 1e18;

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

ll score(int card, vector<ll> playerhand)
{
    ll ans = 0;
    rep(i, 9)
    {
        if (i == card)
        {
            ans += (i + 1) * rpow(10, playerhand[i] + 1, mod);
        }
        else
        {
            ans += (i + 1) * rpow(10, playerhand[i], mod);
        }
        // debug(ans)
    }
    return ans;
}

double solve(int taka, int aoki)
{
    debug(taka);
    double prob_t = leftover[taka] / hand;
    ll taka_score = score(taka, hand_taka);
    debug(taka_score);
    debug(aoki);
    double prob_a = leftover[aoki] / hand;
    ll aoki_score = score(aoki, hand_aoki);
    debug(aoki_score);
    if (taka_score > aoki_score)
    {
        return prob_t * prob_a;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    cin >> k >> s >> t;
    hand = 9 * k - 8;
    leftover.resize(9, 2*k);
    hand_taka.resize(9, 0);
    hand_aoki.resize(9, 0);
    rep(i, 4)
    {
        int now = s[i] - '1';
        leftover[now]--;
        hand_taka[now]++;
    }
    rep(i, 4)
    {
        int now = t[i] - '1';
        leftover[now]--;
        hand_aoki[now]++;
    }
    print_vector<double>(leftover);
    double ans = 0;
    rep(i, 9)
    {
        rep(j, 9)
        {
            ans += solve(i, j);
        }
    }
    cout << ans << endl;
}