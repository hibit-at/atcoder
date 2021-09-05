#include <algorithm>
#include <iostream>
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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    vector<int> ans(n);
    rep(i, n)
    {
        int q;
        cin >> q;
        ans[q - 1] = i + 1;
    }
    rep(i, n)
    {
        cout << ans[i];
        if (i < n - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
}