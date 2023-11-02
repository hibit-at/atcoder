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
    vector<int> st = {0, 3, 6, 9};
    rep(target, 10)
    {
        int n = st.size();
        int ng = -1;
        int ok = n;
        while (abs(ng - ok) > 1)
        {
            int mid = ng + ok;
            mid /= 2;
            if (st[mid] > target)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        cout << st[ng] << endl;
    }
}