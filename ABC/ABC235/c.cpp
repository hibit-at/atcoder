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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, vector<int>> buc;
    rep(i, n)
    {
        int a;
        cin >> a;
        buc[a].push_back(i + 1);
    }
    rep(_, q)
    {
        int x, t;
        cin >> x >> t;
        if (t <= buc[x].size())
        {
            cout << buc[x][t - 1] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}