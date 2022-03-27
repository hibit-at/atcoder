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

vector<vector<int>> to;
vector<bool> seen;
vector<int> ans;

void dfs(int now)
{
    if(seen[now]){
        return;
    }
    debug(now);
    seen[now] = true;
    for (int next : to[now])
    {
        if (seen[next])
        {
            continue;
        }
        dfs(next);
    }
    ans.push_back(now);
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    print_vector(ans);
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    seen.resize(n);
    to.resize(n, vector<int>(0));
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
    }
    rep(i, n)
    {
        dfs(i);
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    reverse(all(ans));
    print_vector(ans);
}