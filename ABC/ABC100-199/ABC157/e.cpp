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

#include <atcoder/segtree>
using namespace atcoder;

int op(int a, int b)
{
    return max(a, b);
}

int e()
{
    return 0;
}

int main(void)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    segtree<int, op, e> st(n);
    vector<segtree<int, op, e>> vst(26, segtree<int, op, e>(n));
    rep(i, n)
    {
        int alpha = s[i] - 'a';
        vst[alpha].set(i, 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int L = 0, R = 0;
            cin >> L >> R;
            int ans = 0;
            rep(alpha, 26)
            {
                ans += vst[alpha].prod(L - 1, R);
            }
            cout << ans << endl;
        }
        if (t == 1)
        {
            int i;
            cin >> i;
            i--;
            char c;
            cin >> c;
            int now_alpha = s[i] - 'a';
            vst[now_alpha].set(i, 0);
            int next_alpha = c - 'a';
            vst[next_alpha].set(i, 1);
            s[i] = c;
        }
    }
}