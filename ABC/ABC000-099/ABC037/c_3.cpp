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

struct SegmentTree
{
    int n;
    vector<ll> node;

    SegmentTree(vector<ll> v)
    {
        int size = v.size();
        n = 1;
        while (n < size)
        {
            n *= 2;
        }
        node.resize(2 * n - 1, 0);

        rep(i, size)
        {
            node[i + n - 1] = v[i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            node[i] = node[2 * i + 1] + node[2 * i + 2];
        }
    }

    ll getSum(int a, int b, int k = 0, int L = 0, int R = -1)
    {
        if (b < a)
        {
            return -getSum(b, a);
        }

        if (R < 0)
        {
            R = n;
        }

        if (R <= a || b <= L)
        {
            return 0;
        }

        if (a <= L && R <= b)
        {
            return node[k];
        }

        ll vL = getSum(a, b, 2 * k + 1, L, (L + R) / 2);
        ll vR = getSum(a, b, 2 * k + 2, (L + R) / 2, R);
        return vL + vR;
    }
};

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    SegmentTree st(a);
    ll ans = 0;
    rep(i, k)
    {
        ans += st.getSum(i, n - i);
    }
    cout << ans << endl;
}