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
    vector<pair<int, int>> choco(n);
    vector<pair<int, int>> box(m);
    rep(i, n)
    {
        choco[i] = {a[i], b[i]};
    }
    rep(i, m)
    {
        box[i] = {c[i], d[i]};
    }
    sort(all(choco));
    sort(all(box));
    int count = 0;
    rep(i, m)
    {
        int xa = choco[count].first;
        int xb = choco[count].second;
        int xc = box[i].first;
        int xd = box[i].second;
        // debug(xa);
        // debug(xb);
        // debug(xc);
        // debug(xd);
        if (xa > xc || xb > xd)
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    // debug(count);
    if (count >= n)
    {
        cout << "Yes" << endl;
        return 0;
    }
    rep(i, n)
    {
        choco[i] = {b[i], a[i]};
    }
    rep(i, m)
    {
        box[i] = {d[i], c[i]};
    }
    sort(all(choco));
    sort(all(box));
    count = 0;
    rep(i, m)
    {
        int xa = choco[count].second;
        int xb = choco[count].first;
        int xc = box[i].second;
        int xd = box[i].first;
        // debug(xa);
        // debug(xb);
        // debug(xc);
        // debug(xd);
        if (xa > xc || xb > xd)
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    if (count >= n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}