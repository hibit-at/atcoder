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

struct LazySegmentTree
{
    int n;
    vector<ll> node;
    vector<ll> lazy;

    LazySegmentTree(vector<ll> v)
    {
        int sz = v.size();
        n = 1;
        while (n < sz)
        {
            n *= 2;
        }
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1);
        rep(i, sz)
        {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            // node[i] += max(node[2 * i + 1], node[2 * i + 2]);
            node[i] = node[2 * i + 1] + node[2 * i + 2];
        }
    }

    void eval(int k, int L, int R)
    {
        if (lazy[k] == 0)
        {
            return;
        }
        node[k] += lazy[k];
        if (L + 1 < R)
        {
            lazy[k * 2 + 1] += lazy[k] / 2;
            lazy[k * 2 + 2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }

    void add_span(int a, int b, ll x, int k = 0, int L = 0, int R = -1)
    {
        if (R < 0)
        {
            R = n;
        }
        eval(k, L, R);
        if (b <= L || R <= a)
        {
            return;
        }
        if (a <= L && R <= b) // 完全に内側の時
        {
            lazy[k] += (R - L) * x;
            eval(k, L, R);
        }
        else
        {
            add_span(a, b, x, k * 2 + 1, L, (L + R) / 2);
            add_span(a, b, x, k * 2 + 2, (L + R) / 2, R);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
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
        eval(k, L, R);
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
    vector<ll> init(2e5+10, 0);
    LazySegmentTree lst(init);
    rep(i, q)
    {
        int s, t;
        ll p;
        cin >> s >> t;
        s--;
        lst.add_span(s, t, 1);
        // debug("node_and_lazy");
        // print_vector(lst.node);
        // print_vector(lst.lazy);
    }
    rep(i, n)
    {
        cout << lst.getSum(i, i + 1) % 2;
    }
    cout << endl;
}