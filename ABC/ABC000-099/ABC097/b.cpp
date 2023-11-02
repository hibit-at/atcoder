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
    set<int> st;
    st.insert(1);
    rep(i, 1001)
    {
        if (i <= 1)
        {
            continue;
        }
        if (i * i > 1001)
        {
            break;
        }
        int pos = i * i;
        while (pos <= 1000)
        {
            st.insert(pos);
            pos *= i;
        }
    }
    int x;
    cin >> x;
    auto upper = st.upper_bound(x);
    upper--;
    cout << *upper << endl;
}