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

int diff(string s, string t)
{
    int n = s.size();
    int ans = 0;
    rep(i, n)
    {
        ans += (s[i] != t[i]);
    }
    return ans;
}

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

int main(void)
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int ans = 1e9;
    rep(i, n - m + 1)
    {
        chmin(ans, diff(s.substr(i, m), t));
    }
    cout << ans << endl;
}