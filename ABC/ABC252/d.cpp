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

int main(void)
{
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    auto print_map = [](auto mp)
    {
        for (auto p : mp)
        {
            cout << "key : " << p.first << ", value : " << p.second << endl;
        }
    };
    // print_map(mp);
    vector<ll> v(0);
    for (auto p : mp)
    {
        v.push_back(p.second);
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // print_vector(v);
    int m = v.size();
    vector<vector<ll>> dp(m + 1, vector<ll>(4, 0));
    dp[0][0] = 1;
    rep(i, m)
    {
        rep(j, 4)
        {
            if (dp[i][j] == 0)
            {
                continue;
            }
            dp[i + 1][j] += dp[i][j];
            if (j < 3)
            {
                dp[i + 1][j + 1] += dp[i][j] * v[i];
            }
        }
    }
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        }
    };
    // print_vector_vector(dp);
    cout << dp.back().back() << endl;
}