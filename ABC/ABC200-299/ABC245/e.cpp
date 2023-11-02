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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    rep(i, m)
    {
        cin >> c[i];
    }
    rep(i, m)
    {
        cin >> d[i];
    }
    vector<pair<pair<int, int>, int>> allset;
    rep(i, n)
    {
        allset.push_back({{a[i], b[i]}, 0});
    }
    rep(i, m)
    {
        allset.push_back({{c[i], d[i]}, 1});
    }
    sort(all(allset));
    reverse(all(allset));
    multiset<int> workset;
    for (auto now : allset)
    {
        int type = now.second;
        int height = now.first.first;
        int width = now.first.second;
        // debug(type);
        // debug(height);
        // debug(width);
        if (type == 1)
        {
            workset.insert(width);
        }
        else
        {
            auto where = workset.lower_bound(width);
            if (where == workset.end())
            {
                cout << "No" << endl;
                return 0;
            }
            workset.erase(where);
        }
    }
    cout << "Yes" << endl;
    return 0;
}