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

int func(int n, int L, int R)
{
    if (n == 0)
    {
        return 1;
    }
    if (L > R)
    {
        return 0;
    }
    return func(n - 1, L + 1, R) + func(n, L + 1, R);
}

int main(void)
{
    int n, L, R;
    cin >> n >> L >> R;
    cout << func(n, L, R) << endl;
}