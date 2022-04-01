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

int main(void)
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    const int inf = 2e9;
    vector<int> dp(n + 1, inf);
    dp[n] = 0;
    vector<int> buc(n + 1, inf);
    int max_reach = n;
    for (int i = n; i >= 0; i--)
    {
        i = max_reach;
        debug(i);
        if (s[i] == '1')
        {
            max_reach--;
            continue;
        }
        bool allWall = true;
        rep(j, m + 1)
        {
            int next = i - j;
            if (next < 0)
            {
                continue;
            }
            if (s[next] == '1')
            {
                continue;
            }
            allWall = false;
            auto chmin = [](auto &a, auto b)
            { a = min(a, b); };
            chmin(dp[next], dp[i] + 1);
            if (dp[next] < inf)
            {
                chmin(buc[dp[next]], next);
            }
            max_reach = next;
        }
        if (!allWall)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << (i == inf ? -1 : i) << ',';
        }
        cout << endl;
    };
    print_vector(dp);
    if (dp.front() == inf)
    {
        cout << -1 << endl;
        return 0;
    }
    int pos = 0;
    int buf = 0;
    vector<int> ans(0);
    while (pos < n)
    {
        int last = dp[pos];
        while (last <= dp[pos])
        {
            pos++;
            buf++;
        }
        ans.push_back(buf);
        buf = 0;
    }
    auto print_join = [](auto v)
    {
        int size = v.size();
        rep(i, size)
        {
            if (i < size - 1)
            {
                cout << v[i] << ' ';
            }
            else
            {
                cout << v[i] << endl;
            }
        }
    };
    print_join(ans);
}