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

const int inf = 1e5;

int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n - 1)
    {
        pair<int, int> where_min(n, inf);
        for (int j = i; j < n; j++)
        {
            if (a[j] < where_min.first)
            {
                where_min.first = a[j];
                where_min.second = j;
            }
        }
        swap(a[i], a[where_min.second]);
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