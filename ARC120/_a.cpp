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

vector<ll> a, peak, sum, sum_sum;

int main(void)
{
    int n;
    cin >> n;
    a.resize(n);
    peak.resize(n);
    sum.resize(n);
    sum_sum.resize(n);
    rep(i, n)
    {
        cin >> a[i];
        if (i == 0)
        {
            peak[i] = a[i];
            sum[i] = a[i];
            sum_sum[i] = sum[i];
        }
        else
        {
            peak[i] = max(peak[i - 1], a[i]);
            sum[i] = sum[i - 1] + a[i];
            sum_sum[i] = sum_sum[i - 1] + sum[i];
        }
    }
    rep(i, n)
    {
        cout << peak[i] * ll(i + 1) + sum_sum[i] << endl;
    }
}