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
    int n;
    cin >> n;
    ll mask = 0;
    rep(i, n)
    {
        int t;
        cin >> t;
        if (mask < (1LL << t))
        {
            mask = (1LL << t);
        }
        else
        {
            if (mask % (1LL << t) != 0)
            {
                while ((mask % (1LL << t)) != 0)
                {
                    mask *= 2;
                }
            }
            else
            {
                mask = mask | (1 << t);
            }
        }
    }
    cout << mask << endl;
}