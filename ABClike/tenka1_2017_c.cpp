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
    ll n;
    cin >> n;
    rep1(i, 3500)
    {
        rep1(j, 3500)
        {
            ll top = n * i * j;
            ll bottom = 4 * i * j - n * i - n * j;
            if(bottom <= 0){
                continue;
            }
            if (top % bottom == 0)
            {
                ll k = top / bottom;
                cout << i << ' ' << j << ' ' << k << endl;
                return 0;
            }
        }
    }
}