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

int n;
vector<vector<int>> to;
vector<bool> seen;
vector<pair<int, int>> ans;
int border;

void dfs(int now)
{
    if (seen[now])
    {
        return;
    }
    seen[now] = true;
    // debug(now);
    ans[now].first = border;
    vector<int> children;
    for (int next : to[now])
    {
        if (seen[next])
        {
            continue;
        }
        children.push_back(next);
    }
    int size = children.size();
    rep(i, size)
    {
        int next = children[i];
        dfs(next);
        if (i < size - 1)
        {
            border++;
        }
    }
    ans[now].second = border;
    return;
}

int main(void)
{
    cin >> n;
    to.resize(n + 1, vector<int>());
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    seen.resize(n + 1, false);
    ans.resize(n + 1, {0, 0});
    border = 1;
    dfs(1);
    rep1(i, n)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}