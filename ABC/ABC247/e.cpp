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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    int posX = -1;
    int posY = -1;
    int b = -1;
    ll ans = 0;
    rep(i, n)
    {
        if (a[i] == x)
        {
            posX = i;
        }
        if (a[i] == y)
        {
            posY = i;
        }
        if (a[i] < y || x < a[i])
        {
            b = i;
        }
        ans += max(0, min(posX, posY) - b);
    }
    cout << ans << endl;
}