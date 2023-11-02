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
    string s;
    cin >> s;
    stack<int> st;
    for (char c : s)
    {
        if (st.size() == 0)
        {
            st.push(c);
        }
        else
        {
            if (st.top() != c)
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
    }
    // debug(s.size());
    // debug(st.size());
    cout << s.size() - st.size() << endl;
}