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
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n)
    {
        cin >> s[i];
    }
    int ans = 0;
    int q;
    cin >> q;
    rep(i, q)
    {
        int t;
        cin >> t;
        int ng = -1;
        int ok = n;
        while (abs(ng - ok) > 1)
        {
            int mid = ok + ng;
            mid /= 2;
            if (s[mid] >= t)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        if (s[ok] == t)
        {
            ans++;
        }
    }
    cout << ans << endl;
}