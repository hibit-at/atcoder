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
void chmax(T &a, T b) { a = max(a, b); }

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

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
    int T;
    cin >> T;
    vector<vector<int>> g(T, vector<int>(T));
    rep(i, T)
    {
        rep(j, T)
        {
            cin >> g[i][j];
        }
    }
    vector<int> dp(T + 2);
    rep(t, T + 2)
    {
        rep(i, t)
        {
            for (int j = i + 1; j < t; j++)
            {
                chmax(dp[t], dp[i] + g[i][j - 1]);
            }
        }
    }
    // print_vector(dp);
    cout << dp[T + 1] << endl;
}