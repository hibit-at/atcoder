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
        cout << i << ',';
    }
    cout << endl;
    return;
}

int WF(int start, vector<vector<int>> to)
{
    vector<int> dp(10, inf);
    dp[start] = 0;
    rep(k, 10)
    {
        rep(i, 10)
        {
            rep(j, 10)
            {
                int cost = min(to[i][j], to[i][k] + to[k][j]);
                chmin(dp[j], dp[i] + cost);
            }
        }
    }
    // print_vector(dp);
    vector<int> ans;
    for(int d : dp){
        if(d == inf){
            continue;
        }
        ans.push_back(d);
    }
    if(ans.size() == 1){
        return inf;
    }
    return accumulate(all(ans),0);
}

void solve(int n)
{
    vector<vector<int>> to(10, vector<int>(10, inf));
    rep(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        to[a][b] = c;
        to[b][a] = c;
    }
    int ans_key = 0;
    int ans_value = inf;
    rep(i, 10)
    {
        int tmp_value = WF(i, to);
        if (tmp_value < ans_value)
        {
            ans_key = i;
            ans_value = tmp_value;
        }
    }
    cout << ans_key << ' ' << ans_value << endl;
}

int main(void)
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        solve(n);
    }
}