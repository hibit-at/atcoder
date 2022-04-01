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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    ll sum = accumulate(all(a), 0LL);
    // debug(sum);
    if ((x + y) != sum)
    {
        cout << "No" << endl;
        return 0;
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
    queue<ll> q;
    for (ll i : a)
    {
        q.push(ll(i));
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
    auto check_func = [&](queue<ll> q, ll target)
    {
        ll check = 0;
        queue<ll> work;
        while (q.size() > 0)
        {
            ll now = q.front();
            q.pop();
            work.push(now);
            check += now;
            if (check == target)
            {
                return true;
            }
            while (check > target)
            {
                check -= work.front();
                work.pop();
            }
            if (check == target)
            {
                return true;
            }
        }
        return false;
    };
    if (check_func(q, x))
    {
        cout << "Yes" << endl;
    }
    else if (check_func(q, y))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}