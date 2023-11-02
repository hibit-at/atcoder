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

vector<vector<int>> b(2, vector<int>(3));
vector<vector<int>> c(3, vector<int>(2));
vector<vector<char>> state(3, vector<char>(3, '.'));
vector<vector<bool>> seen(3, vector<bool>(3));
vector<int> memo(19683, -1);

const int inf = 1e9;

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int bit()
{
    int step = 1;
    int ans = 0;
    rep(i, 3)
    {
        rep(j, 3)
        {
            if (state[i][j] == 'o')
            {
                ans += step * 1;
            }
            if (state[i][j] == 'x')
            {
                ans += step * 2;
            }
            step *= 3;
        }
    }
    return ans;
}

int dfs(int step)
{
    if (memo[bit()] > -1)
    {
        return memo[bit()];
    }
    if (step == 9)
    {
        int score = 0;
        rep(i, 2)
        {
            rep(j, 3)
            {
                if (state[i][j] == state[i + 1][j])
                {
                    score += b[i][j];
                }
            }
        }
        rep(i, 3)
        {
            rep(j, 2)
            {
                if (state[i][j] == state[i][j + 1])
                {
                    score += c[i][j];
                }
            }
        }
        return memo[bit()] = score;
    }
    int ans;
    if (step % 2 == 0)
    {
        ans = 0;
    }
    else
    {
        ans = inf;
    }
    rep(i, 3)
    {
        rep(j, 3)
        {
            if (state[i][j] != '.')
            {
                continue;
            }
            if (step % 2 == 0)
            {
                state[i][j] = 'o';
                chmax(ans, dfs(step + 1));
            }
            else
            {
                state[i][j] = 'x';
                chmin(ans, dfs(step + 1));
            }
            state[i][j] = '.';
        }
    }
    return memo[bit()] = ans;
}

int main(void)
{
    int sum = 0;
    rep(i, 2)
    {
        rep(j, 3)
        {
            cin >> b[i][j];
        }
        sum += accumulate(all(b[i]), 0);
    }
    rep(i, 3)
    {
        rep(j, 2)
        {
            cin >> c[i][j];
        }
        sum += accumulate(all(c[i]), 0);
    }
    int score = dfs(0);
    cout << score << endl;
    cout << sum - score << endl;
}