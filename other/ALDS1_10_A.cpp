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

vector<int> memo;
vector<vector<int>> to;
int n;

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

int dfs(int now)
{
    if (now < 0)
    {
        return 0;
    }
    if (memo[now] > -1)
    {
        return memo[now];
    }
    int ans = 0;
    for (int from : to[now])
    {
        ans += dfs(from);
    }
    print_vector(memo);
    return memo[now] = ans;
}

int main(void)
{
    cin >> n;
    to.resize(n + 1);
    memo.resize(n + 1, -1);
    memo[0] = 1;
    rep(i, n + 1)
    {
        to[i].push_back(i - 1);
        to[i].push_back(i - 2);
    }
    cout << dfs(n) << endl;
}