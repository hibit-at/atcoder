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

string encode(int n)
{
    if (n == 9)
    {
        return "IX";
    }
    if (n == 0)
    {
        return "XII";
    }
    string ans = "";
    while (n >= 10)
    {
        ans.push_back('X');
        n -= 10;
    }
    while (n >= 5)
    {
        ans.push_back('V');
        n -= 5;
    }
    while (n >= 1)
    {
        ans.push_back('I');
        n--;
    }
    return ans;
}

int decode(string s)
{
    if (s == "IX")
    {
        return 9;
    }
    int ans = 0;
    for (char c : s)
    {
        if (c == 'I')
        {
            ans++;
        }
        if (c == 'V')
        {
            ans += 5;
        }
        if (c == 'X')
        {
            ans += 10;
        }
    }
    return ans;
}

int main(void)
{
    string s;
    int t;
    cin >> s >> t;
    int n = decode(s);
    // debug(n);
    n += t;
    n %= 12;
    n += 12;
    n %= 12;
    // debug(n);
    cout << encode(n) << endl;
}