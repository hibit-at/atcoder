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
    ll n, k, x;
    cin >> n >> k >> x;
    ll ans = 0;
    ll stock = 0;
    ll sum = 0;
    vector<ll> left(0);
    rep(i, n)
    {
        ll a;
        cin >> a;
        sum += a;
        stock += a / x;
        left.push_back(a % x);
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // debug(sum);
    // debug(stock);
    // print_vector(left);
    if (k <= stock)
    {
        cout << sum - k * x << endl;
        return 0;
    }
    else
    {
        sum -= stock * x;
        k -= stock;
        // debug(sum);
        // debug(k);
        sort(all(left));
        reverse(all(left));
        queue<ll> q;
        for (ll i : left)
        {
            q.push(i);
        }
        auto print_front = [](auto q)
        {
            while (q.size() > 0)
            {
                cout << q.front() << ',';
                q.pop();
            }
            cout << endl;
        };
        // print_front(q);
        while (q.size() > 0 && k > 0)
        {
            k--;
            ll now = q.front();
            q.pop();
            sum -= now;
            if (sum < 0)
            {
                sum = 0;
                break;
            }
        }
        cout << sum << endl;
    }
}