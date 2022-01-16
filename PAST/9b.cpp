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

int calc(int n)
{
    vector<int> coins = {500, 100, 50, 10, 5, 1};
    int ans = 0;
    for (int c : coins)
    {
        if (n >= c)
        {
            if (c == 50 || c == 5)
            {
                ans += n / c;
            }
            n %= c;
        }
    }
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    int ans = 0;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        int left = b - a;
        ans += calc(left);
    }
    cout << ans << endl;
}