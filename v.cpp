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
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
        a[i] -= i + 1;
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // print_vector(a);
    sort(all(a));
    ll med = a[n / 2];
    ll ans = 0;
    rep(i, n)
    {
        ans += abs(a[i] - med);
    }
    cout << ans << endl;
}