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

int n, x;
vector<int> a;

bool func(int now_pos, int now_val)
{
    // debug(now_val);
    if (now_pos == n)
    {
        return now_val == x;
    }
    bool sub1 = func(now_pos + 1, now_val);
    bool sub2 = func(now_pos + 1, now_val + a[now_pos]);
    return sub1 || sub2;
}

int main(void)
{
    cin >> n >> x;
    a.resize(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    if (func(0, 0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}