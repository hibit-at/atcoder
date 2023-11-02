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
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i, n)
    {
        string s;
        int d;
        cin >> s >> d;
        if (s == "East")
        {
            ans += clamp(d, a, b);
        }
        else
        {
            ans -= clamp(d, a, b);
        }
    }
    if (ans > 0)
    {
        cout << "East " << ans << endl;
    }
    else if (ans == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << "West " << -ans << endl;
    }
}