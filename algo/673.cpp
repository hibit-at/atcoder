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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n, vector<int>());
    if (m == 0)
    {
        return 0;
    }
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<pair<int, int>> vp(n);
    rep(i, n)
    {
        vp[i] = {-to[i].size(), i};
    }
    sort(all(vp));
    int popular = vp[0].second;
    sort(all(to[popular]));
    int size = to[popular].size();
    rep(i, size)
    {
        cout << to[popular][i];
        if (i < size - 1)
        {
            cout << ' ';
        }
    }
    cout << endl;
}