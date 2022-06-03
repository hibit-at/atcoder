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
    vector<vector<int>> a(3, vector<int>(n));
    rep(i, 3)
    {
        rep(j, n)
        {
            cin >> a[i][j];
        }
    }
    const int inf = 2e9;
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                if (i == inf)
                {
                    cout << "-,";
                }
                else
                {
                    cout << i << ',';
                }
            }
            cout << endl;
        }
    };
    // print_vector_vector(a);
    vector<vector<int>> dp(n + 1, vector<int>(101, inf));
    rep(i, 101)
    {
        dp[0][i] = 0;
    }
    auto chmin = [](auto &a, auto b)
    { a = min(a, b); };
    rep(i, n)
    {
        rep(j, 101)
        {
            rep(k, 3)
            {
                int next = a[k][i];
                chmin(dp[i + 1][next], dp[i][j] + abs(j - next));
            }
        }
    }
    // print_vector_vector(dp);
    cout << *min_element(all(dp.back())) << endl;
}