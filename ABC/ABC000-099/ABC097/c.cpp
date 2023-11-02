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
    int k;
    cin >> k;
    int n = s.size();
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // debug(i);
            // debug(j);
            int span = j - i;
            if (span > k)
            {
                continue;
            }
            st.insert(s.substr(i, span));
        }
    }
    auto itr = st.begin();
    k--;
    while (k--)
    {
        itr++;
    }
    cout << *itr << endl;
}