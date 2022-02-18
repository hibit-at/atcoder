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
    int t;
    cin >> t;
    rep(_, t)
    {
        ll a, s;
        cin >> a >> s;
        if (s - a * 2 < 0)
        {
            cout << "No" << endl;
            continue;
        }
        ll left = s - a * 2;
        bool isFail = false;
        // rep(i, 60)
        // {
        //     bool abit = (a >> i) & 1;
        //     cout << abit;
        // }
        // cout << endl;
        // rep(i, 60)
        // {
        //     bool leftbit = (left >> i) & 1;
        //     cout << leftbit;
        // }
        // cout << endl;
        rep(i, 60)
        {
            bool abit = (a >> i) & 1;
            bool sbit = (left >> i) & 1;
            if (sbit && abit)
            {
                isFail = true;
                break;
            }
        }
        if (isFail)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}