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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    ll x = 0;
    map<ll, int> check;
    int loop_value = -1;
    rep(i, k)
    {
        x += a[x % n];
        if (check[x % n] > 0)
        {
            loop_value = x % n;
            break;
        }
        check[x % n]++;
    }
    if (loop_value == -1)
    {
        cout << x << endl;
        return 0;
    }
    // debug(loop_value);
    vector<ll> loop_vector(0);
    x = 0;
    bool is_loop_start = false;
    int loop_start = -1;
    rep(i, k)
    {
        x += a[x % n];
        // debug(x);
        if (x % n == loop_value && is_loop_start)
        {
            break;
        }
        if (x % n == loop_value && !is_loop_start)
        {
            is_loop_start = true;
            loop_start = i + 1;
        }
        if (is_loop_start)
        {
            loop_vector.push_back(a[x % n]);
        }
    }
    // print_vector(loop_vector);
    ll ans = 0;
    x = 0;
    // debug(loop_start);
    rep(i, loop_start)
    {
        ans += a[ans % n];
        k--;
    }
    // debug(ans);
    ll loop_sum = accumulate(all(loop_vector), 0LL);
    ll loop_size = loop_vector.size();
    // debug(loop_size);
    ans += k / loop_size * loop_sum;
    ll left = k % loop_size;
    rep(i, left)
    {
        ans += loop_vector[i];
    }
    cout << ans << endl;
}