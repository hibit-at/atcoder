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

bool exists_r(string s)
{
    int n = s.size();
    rep(i, n)
    {
        if (s[i] == 'r')
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    int n = 12;
    int ans = 0;
    while (n--)
    {
        string s;
        cin >> s;
        ans += exists_r(s);
    }
    cout << ans << endl;
}