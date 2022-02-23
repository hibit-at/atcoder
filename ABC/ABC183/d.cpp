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
            node[i] += max(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int x, ll val)
    {
        x += n - 1;

        node[x] += val;
        while (x > 0)
        {
            x = (x - 1) / 2;
            node[x] = max(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    void eval(int k)
    {
        if (lazy[k] == 0)
        {
            return;
        }
        if (k < n - 1)
        {
            lazy[k * 2 + 1] += lazy[k];
            lazy[k * 2 + 2] += lazy[k];
        }
        node[k] += lazy[k];
        lazy[k] = 0;
    }

    void span_update(int a, int b, ll x, int k = 0, int l = 0, int r = -1)
    {
        eval(k);
        if (r < 0)
        {
            r = n;
        }
        if (a <= l && r <= b) // 完全に内側の時
        {
            lazy[k] = x;
            eval(k);
        }
        else if (a < r && l < b) //一部区間がかぶる時
        {
            span_update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            span_update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            node[k] = max(node[k * 2 + 1], node[k * 2 + 2]);
        }
    }

    ll getMax(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
        {
            r = n;
        }
        // cout << l << ' ' << r << endl;
        eval(k);
        if (r <= a || b <= l) // 完全に外側
        {
            return 0;
        }
        if (a <= l && r <= b) // 完全に内側
        {
            return node[k];
        }
        ll vl = getMax(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getMax(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
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
    int n, w;
    cin >> n >> w;
    vector<ll> init(8, 0);
    LazySegmentTree lst(init);
    rep(i, n)
    {
        int s, t;
        ll p;
        cin >> s >> t >> p;
        lst.span_update(s, t, p);
        debug("node_and_lazy");
        print_vector(lst.node);
        print_vector(lst.lazy);
    }
    if (lst.getMax(0, n) > w)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}