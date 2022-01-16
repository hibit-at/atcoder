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

int main(void)
{
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
    dp[0][0] = 0;
    rep(i, n+1)
    {
        rep(j, m+1)
        {
            if(i+1 <= n){
                chmin(dp[i+1][j],dp[i][j] + 1);
            }
            if(j+1 <= m){
                chmin(dp[i][j+1],dp[i][j] + 1);
            }
            if(i+1 <= n && j+1 <= m){
                int cost = 1;
                if(s[i] == t[j]){
                    cost = 0;
                }
                chmin(dp[i+1][j+1],dp[i][j] + cost);
            }
        }
    }
    // print_vector_vector(dp);
    cout << dp[n][m] << endl;
}