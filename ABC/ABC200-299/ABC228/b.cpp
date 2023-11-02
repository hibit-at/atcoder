#include <algorithm>
#include <iostream>
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

vector<vector<int>> to;
vector<bool> seen;

int dfs(int now)
{
    if (seen[now])
    {
        return 0;
    }
    seen[now] = true;
    int ans = 1;
    // debug(now);
    for (int next : to[now])
    {
        ans += dfs(next);
    }
    return ans;
}

int main(void)
{
    int n, x;
    cin >> n >> x;
    to.resize(n + 1);
    seen.resize(n + 1);
    rep1(i, n)
    {
        int a;
        cin >> a;
        to[i].push_back(a);
    }
    cout << dfs(x) << endl;
}