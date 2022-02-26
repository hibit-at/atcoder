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

    void eval(int k)
    {
        if (lazy[k] == 0)
        {
            return;
        }
        node[k] += lazy[k];
        if (k < n - 1)
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
        eval(k);
        if (b <= L || R <= a)
        {
            return;
        }
        if (a <= L && R <= b) // 完全に内側の時
        {
            lazy[k] += (R - L) * x;
            eval(k);
        }
        else
        {
            add_span(a, b, x, k * 2 + 1, L, (L + R) / 2);
            add_span(a, b, x, k * 2 + 2, (L + R) / 2, R);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
        print_vector(this->node);
        print_vector(this->lazy);
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
        eval(k);
        if (a <= L && R <= b) // 完全に内側
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
    vector<ll> init = {1, 3, 5, 7, 9, 11, 13, 15};
    LazySegmentTree lst(init);
    lst.add_span(1, 7, 1);
    lst.add_span(0, 4, 2);
    rep(i, 8)
    {
        cout << lst.getSum(0, 8) << endl;
    }
    print_vector(lst.node);
    print_vector(lst.lazy);
}