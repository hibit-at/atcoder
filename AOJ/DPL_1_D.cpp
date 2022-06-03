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
struct RMQ
{
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n_) : n(), dat(n_ * 4, 0)
    {
        int x = 1;
        while (n_ > x)
        {
            x *= 2;
        }
        n = x;
    }
    void update(int i, T x)
    {
        i += n - 1;
        dat[i] = x;
        while (i > 0)
        {
            i = (i - 1) / 2;
            dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
        {
            return 0;
        }
        else if (a <= l && r <= b)
        {
            return dat[k];
        }
        else
        {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
};

template <typename T>
struct Compress
{
    vector<T> xs;

    Compress() = default;

    Compress(const vector<T> &vs)
    {
        add(vs);
    }

    Compress(const initializer_list<vector<T>> &vs)
    {
        for (auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs)
    {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x)
    {
        xs.emplace_back(x);
    }

    void build()
    {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const
    {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x)
                  { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
        return ret;
    }

    int get(const T &x) const
    {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](int k) const
    {
        return xs[k];
    }
};

int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    Compress<int> comp(a);
    comp.build();
    a = comp.get(a);
    RMQ<int> dp(n + 1);
    rep(i, n)
    {
        a[i]++;
        dp.update(a[i], dp.query(0, a[i]) + 1);
    }
    cout << dp.query(0, n + 1) << endl;
}