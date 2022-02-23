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

template <typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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
            node[i] = gcd(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    ll getGCD(int a, int b, int k = 0, int L = 0, int R = -1)
    {
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

        ll vL = getGCD(a, b, 2 * k + 1, L, (L + R) / 2);
        ll vR = getGCD(a, b, 2 * k + 2, (L + R) / 2, R);
        return gcd(vL, vR);
    }
};

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    SegmentTree st(a);
    ll ans = 0;
    rep(i, n)
    {
        ll gcd_left = st.getGCD(0, i);
        ll gcd_right = st.getGCD(i + 1, n);
        chmax(ans, gcd(gcd_left, gcd_right));
    }
    cout << ans << endl;
}