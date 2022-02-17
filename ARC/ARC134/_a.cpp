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
    int n;
    ll L, w;
    cin >> n >> L >> w;
    vector<ll> a(n + 1);
    a[0] = -w;
    rep1(i, n)
    {
        cin >> a[i];
    }
    a.push_back(L);
    // print_vector(a);
    ll ans = 0;
    rep(i, n + 1)
    {
        ll last_end = a[i] + w;
        if (last_end < a[i + 1])
        {
            ll span = a[i + 1] - last_end;
            ans += (span + w - 1) / w;
        }
    }
    cout << ans << endl;
}