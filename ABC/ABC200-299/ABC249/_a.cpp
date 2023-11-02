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
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    int takahashi_time = x / (a + c) * a;
    int aoki_time = x / (d + f) * d;
    // debug(takahashi_time);
    // debug(aoki_time);
    takahashi_time += min(x % (a + c), a);
    aoki_time += min(x % (d + f), d);
    // debug(takahashi_time);
    // debug(aoki_time);
    int takahashi_dist = takahashi_time * b;
    int aoki_dist = aoki_time * e;
    // debug(takahashi_dist);
    // debug(aoki_dist);
    if (takahashi_dist > aoki_dist)
    {
        cout << "Takahashi" << endl;
    }
    else if (takahashi_dist == aoki_dist)
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << "Aoki" << endl;
    }
}