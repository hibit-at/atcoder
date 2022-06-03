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
    int n, L;
    int k;
    cin >> n >> L >> k;
    set<int> st;
    st.insert(0);
    rep(i, n)
    {
        int a;
        cin >> a;
        st.insert(a);
    }
    st.insert(L);
    int ok = 0;
    int ng = 2 * L + 1;
    while (abs(ok - ng) > 1)
    {
        int mid = ok + ng;
        mid /= 2;
        auto pos = st.begin();
        int cut = -1;
        while (st.lower_bound(*pos+mid) != st.end())
        {
            pos = st.lower_bound(*pos + mid);
            cut++;
        }
        if (cut >= k)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}