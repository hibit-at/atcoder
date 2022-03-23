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

vector<int> memo;

int dfs(int now)
{
    if (memo[now] < inf)
    {
        return memo[now];
    }
    if (now < 1)
    {
        return inf;
    }
    int ans = inf;
    auto chmin = [](auto &a, auto b)
    { a = min(a, b); };
    chmin(ans, dfs(now - 1) + abs(h[now] - h[now - 1]));
    chmin(ans, dfs(now - 2) + abs(h[now] - h[now - 2]));
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // print_vector(memo);
    return memo[now] = ans;
}

int main(void)
{
    int n;
    cin >> n;
    h.resize(n + 1);
    memo.resize(n + 1, inf);
    memo[1] = 0;
    rep1(i, n)
    {
        cin >> h[i];
    }
    cout << dfs(n) << endl;
}