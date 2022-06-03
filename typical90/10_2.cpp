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

int op(int a, int b) { return a + b; }

int e() { return 0; }

int main(void)
{
    int n;
    cin >> n;
    vector<segtree<int, op, e>> vst(2, segtree<int, op, e>(n));
    rep(i, n)
    {
        int c, p;
        cin >> c >> p;
        c--;
        vst[c].set(i, p);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        L--;
        vector<int> ans(0);
        ans.push_back(vst[0].prod(L, R));
        ans.push_back(vst[1].prod(L, R));
        auto print_join = [](auto v)
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
        print_join(ans);
    }
}