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
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

int main(void)
{
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> s(n + 1);
    rep(i, n)
    {
        ll a;
        cin >> a;
        s[i + 1] = s[i] + a;
    }
    auto print_vector = [](auto v)
    {
        int size = v.size();
        int cnt = 1;
        for (auto i : v)
        {
            cout << i;
            if (cnt < size)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
            cnt++;
        }
    };
    // print_vector(s);
    rep(i, n)
    {
        // debug(i);
        if (binary_search(all(s), s[i] + p))
        {
            auto itr1 = lower_bound(all(s), s[i] + p);
            // debug(*itr1);
            ll next_step = *itr1;
            if (binary_search(all(s), next_step + q))
            {
                auto itr2 = lower_bound(all(s), next_step + q);
                // debug(*itr2);
                ll further_step = *itr2;
                if (binary_search(all(s), further_step + r))
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}