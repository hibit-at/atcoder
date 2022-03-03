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

bool isPrime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isLike(ll n)
{
    ll m = (n + 1) / 2;
    if (isPrime(n) && isPrime(m))
    {
        return true;
    }
    return false;
}

int main(void)
{
    vector<int> buc(1e5 + 1);
    rep1(i, 1e5)
    {
        buc[i] = isLike(i);
        buc[i] += buc[i - 1];
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int L, R;
        cin >> L >> R;
        cout << buc[R] - buc[L - 1] << endl;
    }
}