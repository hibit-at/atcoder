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

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

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
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    rep1(i, n)
    {
        rep1(j, n)
        {
            cin >> grid[i][j];
            grid[i][j] += grid[i][j - 1];
        }
        rep1(j, n)
        {
            grid[i][j] += grid[i - 1][j];
        }
    }
    vector<int> dp(n * n + 1);
    rep(start_h, n + 1)
    {
        rep(start_w, n + 1)
        {
            rep(end_h, n + 1)
            {
                if (end_h <= start_h)
                {
                    continue;
                }
                {
                    rep(end_w, n + 1)
                    {
                        if (end_w <= start_w)
                        {
                            continue;
                        }
                        int use = (end_h - start_h) * (end_w - start_w);
                        int value = grid[end_h][end_w] - grid[start_h][end_w] - grid[end_h][start_w] + grid[start_h][start_w];
                        chmax(dp[use], value);
                    }
                }
            }
        }
    }
    rep1(i, n * n)
    {
        chmax(dp[i], dp[i - 1]);
    }
    // print_vector(dp);
    int q;
    cin >> q;
    rep(_, q)
    {
        int p;
        cin >> p;
        cout << dp[p] << endl;
    }
}