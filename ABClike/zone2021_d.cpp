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
    deque<char> d;
    bool isReverse = false;
    for (char c : s)
    {
        if (c == 'R')
        {
            isReverse = !isReverse;
            continue;
        }
        if (isReverse)
        {
            d.push_front(c);
        }
        else
        {
            d.push_back(c);
        }
    }
    if (isReverse)
    {
        reverse(all(d));
    }
    string ans = "*";
    for (char c : d)
    {
        char last = ans.back();
        if (last == c)
        {
            ans.pop_back();
            continue;
        }
        ans.push_back(c);
    }
    reverse(all(ans));
    ans.pop_back();
    reverse(all(ans));
    cout << ans << endl;
}