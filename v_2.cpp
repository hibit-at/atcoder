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
#include <complex>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007; 問題によって使い分け

ostream &operator<<(ostream &os, const mint &i)
{
    os << i.val();
    return os;
}

ostream &operator<<(ostream &os, const vector<mint> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i].val() << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

int main()
{
    mint n = 1;
    vector<mint> v(10,1);
    cout << n << endl;
}