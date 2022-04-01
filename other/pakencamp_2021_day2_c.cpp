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
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    set<int> b;
    rep(i, m)
    {
        int x;
        cin >> x;
        b.insert(x);
    }
    rep(i, n)
    {
        if (b.find(a[i]) != b.end())
        {
            b.erase(b.find(a[i]));
        }
    }
    cout << b.size() << endl;
    for (int i : b)
    {
        cout << i << endl;
    }
}