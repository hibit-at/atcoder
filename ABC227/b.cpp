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
#include <stack>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    vector<bool> safe(1001);
    rep1(a, 334)
    {
        rep1(b, 334)
        {
            int s = 4 * a * b + 3 * a + 3 * b;
            if (s > 1000)
            {
                continue;
            }
            safe[s] = true;
        }
    } 
    int ans = n;
    rep(i, n)
    {
        int s;
        cin >> s;
        ans -= safe[s];
    }
    cout << ans << endl;
}