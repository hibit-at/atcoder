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

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

int a, b, c;

int func(int i, int x, int y)
{
    int ans = 0;
    ans += i * c;
    x -= i / 2;
    y -= i / 2;
    chmax(x, 0);
    chmax(y, 0);
    ans += x * a;
    ans += y * b;
    return ans;
}

int main(void)
{
    int x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 2e9;
    rep(i, max(x, y) * 2 + 1)
    {
        if (i % 2 == 1)
        {
            continue;
        }
        chmin(ans, func(i, x, y));
    }
    cout << ans << endl;
}