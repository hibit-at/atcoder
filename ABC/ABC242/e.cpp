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
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<char> digit = {0,0,1,2}; //上限の指定
        vector<vector<int>> dp(4,vector<int>(2,0));               // 2つ目の[2]は「余裕があるかないか」の判定
        dp[0][1] = 0;
        dp[0][0] = 1; // 0桁目の0は余裕がない組
        rep(i, 3)
        {
            //余裕ある組
            rep(j, 26) dp[i + 1][1] += dp[i][1];
            //余裕ない組
            rep(j, digit[i + 1]) dp[i + 1][1] += dp[i][0];
            dp[i + 1][0] += dp[i][0];
        }
        print_vector_vector(dp);
        cout << dp[3][1] + dp[3][0] << endl; //出力456
    }
}