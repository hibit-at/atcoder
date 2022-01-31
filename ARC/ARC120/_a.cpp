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

vector<ll> peak, sum;

int main(void)
{
    int n;
    cin >> n;
    peak.resize(n + 1);
    sum.resize(n + 1);
    ll a = 0;
    rep(i, n)
    {
        cin >> a;
        peak[i + 1] = max(peak[i], a);
        sum[i + 1] = sum[i] + a;
    }
    ll sum_sum = 0;
    rep1(i, n)
    {
        sum_sum += sum[i];
        cout << peak[i] * ll(i) + sum_sum << endl;
    }
}