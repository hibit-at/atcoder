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
void chmax(T &a, T b) { a = max(a, b); }

struct SpanSegmentTree
{
    int n;
    vector<ll> node;

    SpanSegmentTree(vector<ll> v)
    {
        int sz = v.size();
        n = 1;
        while (n < sz)
        {
            n *= 2;
        }
        node.resize(2 * n - 1);
        rep(i, sz)
        {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            node[i] = node[2 * i + 1] + node[2 * i + 2];
        }
    }

    void add_span(int a, int b, ll x, int k = 0, int L = 0, int R = -1)
    {
        if (R < 0)
        {
            R = n;
        }
        if (b <= L || R <= a)
        {
            return;
        }
        if (L + 1 == R)
        {
            node[k] += x;
            return;
        }
        add_span(a, b, x, k * 2 + 1, L, (L + R) / 2);
        add_span(a, b, x, k * 2 + 2, (L + R) / 2, R);
        node[k] += node[2 * k + 1] + node[2 * k + 2];
    }

    ll getSum(int a, int b, int k = 0, int L = 0, int R = -1)
    {
        if (R < 0)
        {
            R = n;
        }
        if (R <= a || b <= L) // 完全に外側
        {
            return 0;
        }
        if (a <= L && R <= b) // 完全に内側
        {
            return node[k];
        }
        ll vL = getSum(a, b, 2 * k + 1, L, (L + R) / 2);
        ll vR = getSum(a, b, 2 * k + 2, (L + R) / 2, R);
        return vL + vR;
    }
};

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

int main(void)
{
    int n, q;
    cin >> n >> q;
    vector<ll> init(n, 0);
    SpanSegmentTree sst(init);
    rep(i, q)
    {
        int s, t;
        ll p;
        cin >> s >> t;
        s--;
        sst.add_span(s, t, 1);
        // print_vector(sst.node);
    }
    rep(i, n)
    {
        cout << sst.getSum(i, i + 1) % 2;
    }
    cout << endl;
}