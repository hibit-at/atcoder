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

void cookie(ll &a, ll &b)
{
    if (a % 2 == 1)
    {
        a--;
    }
    a /= 2;
    b += a;
}

int main(void)
{
    ll a, b, k;
    cin >> a >> b >> k;
    rep(i, k)
    {
        if (i%2 == 0){
            cookie(a,b);
        }else{
            cookie(b,a);
        }
    }
    cout << a << ' ' << b << endl;
}