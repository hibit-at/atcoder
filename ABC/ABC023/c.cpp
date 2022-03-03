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

int main(void)
{
    int R, C, K;
    int n;
    cin >> R >> C >> K;
    cin >> n;
    vector<int> r(n), c(n);
    rep(i, n)
    {
        cin >> r[i] >> c[i];
    }
    int ans = 0;
    rep1(i, R)
    {
        rep1(j, C)
        {
            int tmp = 0;
            rep(k, n)
            {
                if (r[k] == i || c[k] == j)
                {
                    tmp++;
                }
            }
            if (tmp == K)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}