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

string binary_expression(int n, int d)
{
    string ans = "";
    rep(i, d) { ans.push_back((n >> i & 1) + '0'); }
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    int state = (1 << 10) - 1;
    rep(i, n)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int mask = 0;
        mask |= 1 << a;
        mask |= 1 << b;
        mask |= 1 << c;
        mask |= 1 << d;
        string s;
        cin >> s;
        if (s == "NO")
        {
            mask = ((1 << 10) - 1) ^ mask;
        }
        state &= mask;
    }
    rep(i, 10)
    {
        if ((state >> i) & 1)
        {
            cout << i << endl;
            return 0;
        }
    }
}