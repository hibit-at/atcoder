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

vector<vector<ll>> to;
vector<ll> cost;
vector<bool> seen;

template <typename T>
void print_to(vector<vector<T>> to)
{
    int n = to.size();
    rep(i, n)
    {
        cout << "from " << i << " : to ";
        for (int next : to[i])
        {
            cout << next << ",";
        }
        cout << endl;
    }
}

ll dfs(int now)
{
    ll ans = 0;
    seen[now] = true;
    // debug(now);
    for (int next : to[now])
    {
        if (seen[next])
        {
            continue;
        }
        ans += dfs(next);
    }
    ans += cost[now];
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    to.resize(n + 1);
    cost.resize(n + 1);
    seen.resize(n + 1);
    rep(i, n)
    {
        int t, k;
        cin >> t >> k;
        cost[i + 1] = t;
        rep(j, k)
        {
            int a;
            cin >> a;
            to[i + 1].push_back(a);
        }
    }
    // print_to<ll>(to);
    ll ans = dfs(n);
    cout << ans << endl;
}