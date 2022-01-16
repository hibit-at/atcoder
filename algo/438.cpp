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
vector<vector<int>> memo;

bool func(int now_pos, int now_val)
{
    if (now_val > x)
    {
        return false;
    }
    if (now_pos == n)
    {
        return now_val == x;
    }
    if (memo[now_pos][now_val] > -1)
    {
        return memo[now_pos][now_val] == 1;
    }
    bool sub1 = func(now_pos + 1, now_val);
    bool sub2 = func(now_pos + 1, now_val + a[now_pos]);
    // debug(now_pos);
    // debug(now_val);
    return memo[now_pos][now_val] = sub1 || sub2;
}

int main(void)
{
    cin >> n >> x;
    a.resize(n);
    memo.resize(n, vector<int>(x + 1, -1));
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