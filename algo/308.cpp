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
void chmax(T &a, T b) { a = max(a, b); }

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

int main(void)
{
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    int max = 0;
    rep(i, n)
    {
        cin >> w[i] >> v[i];
        max += w[i];
    }
    chmax(max, W);
    vector<vector<int>> dp(n + 1, vector<int>(max + 1, 0));
    rep(i, n)
    {
        rep(j, max)
        {
            chmax(dp[i + 1][j], dp[i][j]);
            int next = j + w[i];
            if (next <= max)
            {
                chmax(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
            }
        }
    }
    // print_vector_vector(dp);
    cout << dp.back()[W] << endl;
}