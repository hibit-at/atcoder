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
    int n = s.size();
    int ans = 0;
    rep(i, (n+1)/2)
    {
        int rev_i = n - 1 - i;
        // debug(s[i]);
        // debug(s[rev_i]);
        ans += (s[i] != s[rev_i]);
    }
    cout << ans << endl;
}