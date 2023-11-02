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
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    r--;
    c--;
    vector<int> dh = {1, -1, 0, 0};
    vector<int> dw = {0, 0, 1, -1};
    int ans = 0;
    rep(i, 4)
    {
        if (r + dh[i] < 0 || h <= r + dh[i])
        {
            continue;
        }
        if (c + dw[i] < 0 || w <= c + dw[i])
        {
            continue;
        }
        ans++;
    }
    cout << ans << endl;
}