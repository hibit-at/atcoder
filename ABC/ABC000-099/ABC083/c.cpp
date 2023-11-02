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

int a, b, c, d, e, f;
int sugar = 0;
int water = 0;
vector<pair<double, pair<int, int>>> ans;

vector<vector<bool>> memo(3001,vector<bool>(3001));

void dfs(int sugar, int water)
{
    if (sugar + water > f)
    {
        return;
    }
    if (sugar * 100 > water * e)
    {
        return;
    }
    if (memo[sugar][water]){
        return;
    }
    // debug(sugar);
    // debug(water);
    double con = double(sugar) * 100 / double(sugar + water);
    // debug(con);
    ans.push_back({con, {sugar + water, sugar}});
    dfs(sugar, water + 100 * a);
    dfs(sugar, water + 100 * b);
    dfs(sugar + c, water);
    dfs(sugar + d, water);
    memo[sugar][water] = true;
}

int main(void)
{
    cin >> a >> b >> c >> d >> e >> f;
    dfs(0, 0);
    sort(all(ans));
    cout << ans.back().second.first << ' ' << ans.back().second.second << endl;
}