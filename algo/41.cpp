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

const int inf = 1e9;

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (int i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    rep(i, n)
    {
        rep(j, 3)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(3));
    rep(j, 3)
    {
        dp[0][j] = a[0][j];
    }
    rep(i, n - 1)
    {
        rep(from, 3)
        {
            rep(next, 3)
            {
                if (from == next)
                {
                    continue;
                }
                chmax(dp[i + 1][next], dp[i][from] + a[i + 1][next]);
            }
        }
        // print_vector_vector(dp);
    }
    int ans = 0;
    cout << *max_element(all(dp.back())) << endl;
}