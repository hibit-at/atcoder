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
#include <stack>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    while (true)
    {
        bool sorted = true;
        rep(i, n - 1)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                sorted = false;
            }
        }
        if (sorted)
        {
            break;
        }
        rep(i, n)
        {
            cout << a[i];
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
}