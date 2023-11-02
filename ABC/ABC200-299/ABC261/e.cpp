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

string binary_expression(int n, int d)
{
    string ans = "";
    rep(i, d) { ans.push_back((n >> i & 1) + '0'); }
    return ans;
}

int main(void)
{
    int n;
    ll c;
    cin >> n >> c;
    ll mask = (1 << 30) - 1;
    rep(i, n)
    {
        int t;
        ll a;
        cin >> t >> a;
        a += (a << 30);
        if (t == 1)
            mask &= a;
        if (t == 2)
            mask |= a;
        if (t == 3)
            mask ^= a;
        ll subnet = (1 << 30) - 1;
        c = (c & (subnet & mask)) | ((subnet - c) & (mask >> 30));
        cout << c << endl;
    }
}