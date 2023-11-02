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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n)
    {
        cin >> s[i];
    }
    auto solve = [&](char target)
    {
        int ans = 0;
        map<int, bool> used;
        auto chmax = [](auto &a, auto b)
        { a = max(a, b); };
        for (auto reel : s)
        {
            int pos = 0;
            int cnt = 0;
            while (reel[pos] != target)
            {
                cnt++;
                pos = (pos + 1) % 10;
            }
            // debug(cnt);
            while (used[cnt])
            {
                cnt += 10;
            }
            used[cnt] = true;
            // debug(cnt);
            chmax(ans, cnt);
        }
        return ans;
    };
    int ans = 1e9;
    rep(i, 10)
    {
        // debug(i);
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        chmin(ans, solve('0' + i));
    }
    cout << ans << endl;
}