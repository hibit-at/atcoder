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
    vector<int> c(n);
    rep(i, n)
    {
        cin >> c[i];
    }
    double ans = 0;
    rep(i, n)
    {
        int s = 0;
        rep(j, n)
        {
            if (i == j)
            {
                continue;
            }
            if (c[i] % c[j] == 0)
            {
                s++;
            }
        }
        if (s % 2 == 0)
        {
            double top = double(s + 2);
            double bottom = double(2 * s + 2);
            ans += top / bottom;
        }
        else
        {
            ans += double(1) / 2;
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
}