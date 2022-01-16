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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

void shift(string &s)
{
    int n = s.size();
    rep(i, n)
    {
        s[i]++;
        if (s[i] == '{')
        {
            s[i] = 'a';
        }
    }
}

int main(void)
{
    string s, t;
    cin >> s >> t;
    rep(i, 26)
    {
        shift(s);
        if (s == t)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}