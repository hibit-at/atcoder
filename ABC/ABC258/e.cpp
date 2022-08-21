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
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

int main(void)
{
    int n, q, x;
    cin >> n >> q >> x;
    vector<int> w(n);
    cin >> w;
    vector<int> s(n + 1);
    rep(i, n)
    {
        s[i + 1] += s[i] + w[i];
    }
    auto print_vector = [](auto v)
    {
        int size = v.size();
        rep(i, size)
        {
            if (i < size - 1)
            {
                cout << v[i] << ' ';
            }
            else
            {
                cout << v[i] << endl;
            }
        }
    };
    print_vector(s);
    while (q--)
    {
        ll k;
        cin >> k;
        map<int, int> loop_check;
        int pos = 0;
        vector<int> box;
        while (loop_check[pos] < 2)
        {
            debug(pos);
            loop_check[pos]++;
            auto itr = lower_bound(s.begin() + pos, s.end(), s[pos] + x);
            int where = itr - s.begin();
            pos = where;
        }
    }
}