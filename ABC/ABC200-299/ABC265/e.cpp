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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main(void)
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<ll> dx(3), dy(3);
    rep(i, 3)
    {
        cin >> dx[i] >> dy[i];
    }
    map<pair<ll, ll>, int> obstacle;
    rep(i, m)
    {
        ll x, y;
        cin >> x >> y;
        obstacle[{x, y}] = 1;
    }
    auto print_map = [](auto mp)
    {
        for (auto p : mp)
        {
            cout << "key : " << p.first.first << " " << p.first.second << ", value : " << p.second << endl;
        }
    };
    // print_map(obstacle);
    vector<map<pair<ll, ll>, mint>> dp(n + 1);
    dp[0][{0, 0}] = 1;
    rep(i, n)
    {
        // debug(i);
        for (auto [key, val] : dp[i])
        {
            auto print_pair = [](auto p)
            {
                cout << '(' << p.first << ',' << p.second << ')';
            };
            // print_pair(key);
            // debug(val);
            rep(k, 3)
            {
                if (obstacle.count({key.first + dx[k], key.second + dy[k]}) > 0)
                {
                    continue;
                }
                dp[i + 1][{key.first + dx[k], key.second + dy[k]}] += val;
            }
        }
    }
    mint ans = 0;
    for (auto [key, val] : dp[n])
    {
        auto print_pair = [](auto p)
        {
            cout << '(' << p.first << ',' << p.second << ')';
        };
        // print_pair(key);
        // debug(val);
        ans += val;
    }
    cout << ans.val() << endl;
}