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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int win_local = 0;
    int win_foreign = 0;
    rep(i, n)
    {
        int stand = i + 1;
        char c = s[i];
        if (c == 'a')
        {
            if (win_local + win_foreign < a + b)
            {
                cout << "Yes" << endl;
                win_local ++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (c == 'b')
        {
            if ((win_local + win_foreign < a + b) && win_foreign < b)
            {
                cout << "Yes" << endl;
                win_foreign ++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
}