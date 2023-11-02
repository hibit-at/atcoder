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

void print_set(multiset<ll> st)
{
    for (ll s : st)
    {
        cout << s << ',';
    }
    cout << endl;
}

int main(void)
{
    multiset<ll> st;
    int q;
    cin >> q;
    rep(_, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll x;
            cin >> x;
            st.insert(x);
        }
        if (type == 2)
        {
            ll x, k;
            cin >> x >> k;
            auto itr = st.upper_bound(x);
            while (itr != st.begin() && k > 0)
            {
                k--;
                itr--;
            }
            if (k > 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << *itr << endl;
            }
        }
        if (type == 3)
        {
            ll x, k;
            cin >> x >> k;
            auto itr = st.lower_bound(x);
            while (itr != st.end() && k > 1)
            {
                k--;
                itr++;
            }
            if (itr == st.end())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << *itr << endl;
            }
        }
        // print_set(st);
    }
}