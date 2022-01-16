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
void chmin(T &a, T b) { a = min(a, b); }

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    return;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<int> dp(n, inf);
    dp[0] = 0;
    rep(i, n)
    {
        rep1(j, m)
        {
            if (i + j < n)
            {
                chmin<int>(dp[i + j], dp[i] + j * a[i + j]);
            }
        }
        // print_vector(dp);
    }
    cout << dp.back() << endl;
}