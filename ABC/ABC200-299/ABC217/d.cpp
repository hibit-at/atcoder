#include <algorithm>
#include <iostream>
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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

int main()
{
    int L, q;
    cin >> L >> q;
    set<int> st;
    st.insert(0);
    st.insert(L);
    rep(_, q)
    {
        int c, x;
        cin >> c >> x;
        if (c == 1)
        {
            st.insert(x);
        }
        if (c == 2)
        {
            auto right = st.upper_bound(x);
            auto left = st.upper_bound(x);
            left--;
            cout << *right - *left << endl;
        }
    }
}