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

bool isLeft(char c)
{
    int num = c - '0';
    if (1 <= num && num <= 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i, n)
    {
        if (i == 0)
        {
            ans += 500;
            continue;
        }
        if (s[i - 1] == s[i])
        {
            ans += 301;
        }
        else if (isLeft(s[i - 1]) == isLeft(s[i]))
        {
            ans += 210;
        }
        else
        {
            ans += 100;
        }
    }
    cout << ans << endl;
}