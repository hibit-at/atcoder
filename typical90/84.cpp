#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main(void)
{
    ll n;
    string s;
    cin >> n >> s;
    s.push_back('#');
    char last = '#';
    ll tmp = 0;
    ll ans = n * (n - 1) / 2;
    for (char now : s)
    {
        if (now == last)
        {
            tmp++;
        }
        else
        {
            ans -= tmp * (tmp - 1) / 2;
            last = now;
            tmp = 1;
        }
    }
    cout << ans << endl;
}