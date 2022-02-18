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

vector<int> h;

const int inf = 1e9;

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

vector<int> dp;

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

int main(void)
{
    int n;
    cin >> n;
    h.resize(n + 1);
    dp.resize(n + 1, inf);
    dp[1] = 0;
    rep1(i, n)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        chmin(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        if (i + 2 <= n)
        {
            chmin(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
        }
        print_vector(dp);
    }
    cout << dp[n] << endl;
}