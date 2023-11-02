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
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

bool bigger(string s, string t)
{
    int n = s.size();
    int m = t.size();
    if (n > m)
    {
        return true;
    }
    else if (n == m)
    {
        if (s > t)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> c(9);
    cin >> c;
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // print_vector(c);
    int inf = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(10, 0));
    dp[0][0] = 0;
    rep(i, n)
    {
        rep(j, 10)
        {
            rep1(next_j, 9)
            {
                int next_i = i + c[next_j - 1];
                if (next_i <= n)
                {
                    auto chmax = [](auto &a, auto b)
                    { a = max(a, b); };
                    chmax(dp[next_i][next_j], dp[i][j] + 1);
                }
            }
        }
    }
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        }
    };
    print_vector_vector(dp);
}