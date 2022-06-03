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
    multiset<int> st;
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            st.insert(x);
        }
        if (t == 2)
        {
            int x, c;
            cin >> x >> c;
            while (c-- && st.find(x) != st.end())
            {
                st.erase(st.find(x));
            }
        }
        if (t == 3)
        {
            cout << *prev(st.end()) - *st.begin() << endl;
        }
    }
}