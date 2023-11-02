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
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

int main(void)
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(33, vector<int>(n));
    rep(i, n)
    {
        if (s[i] == 'R')
        {
            dp[0][i] = i + 1;
        }
        else
        {
            dp[0][i] = i - 1;
        }
    }
    rep(i, 32)
    {
        rep(j, n)
        {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }
    // print_vector_vector(dp);
    vector<int> ans(n);
    rep(i, n)
    {
        ans[dp[32][i]]++;
    }
    for (int a : ans)
    {
        cout << a << ' ';
    }
    cout << endl;
}