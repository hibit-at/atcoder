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

int n, m, k;


ll dfs(int pos, int sum)
{
    if (sum > k)
    {
        return 0;
    }
    if (pos == n)
    {
        return 1;
    }
    int ans = 0;
    rep1(i, m)
    {
        if (pos + i > n)
        {
            continue;
        }
        ans += dfs(pos + i, sum + i);
    }
    return ans;
}

int main(void)
{
    cin >> n >> m >> k;
    cout << dfs(0, 0) << endl;
}