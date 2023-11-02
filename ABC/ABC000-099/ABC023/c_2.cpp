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
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

int main(void)
{
    int R, C, K;
    int n;
    cin >> R >> C >> K;
    cin >> n;
    vector<int> r(n), c(n);
    vector<int> r_sum(R);
    vector<int> c_sum(C);
    rep(i, n)
    {
        cin >> r[i] >> c[i];
        r_sum[r[i] - 1]++;
        c_sum[c[i] - 1]++;
    }
    vector<int> sorted_c = c_sum;
    sort(all(sorted_c));
    ll ans = 0;
    rep(i, R)
    {
        int target = K - r_sum[i];
        auto upper = upper_bound(all(sorted_c), target);
        auto lower = lower_bound(all(sorted_c), target);
        ll range = upper - lower;
        ans += range;
    }
    rep(i, n)
    {
        if (r_sum[r[i] - 1] + c_sum[c[i] - 1] == K)
        {
            ans--;
        }
    }
    rep(i, n)
    {
        if (r_sum[r[i] - 1] + c_sum[c[i] - 1] == K + 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
}