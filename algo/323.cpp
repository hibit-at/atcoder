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
    vector<int> d(m);
    rep(i, m)
    {
        cin >> d[i];
    }
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    rep(i, n)
    {
        for (int step : d)
        {
            int next = i + step;
            if (next <= n)
            {
                dp[next] = dp[next] | dp[i];
            }
        }
    }
    if (dp[n])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}