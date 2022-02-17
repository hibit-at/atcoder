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
    int n;
    cin >> n;
    vector<int> a(n);
    int target = -1;
    rep(i, n)
    {
        cin >> a[i];
        if (i > 0)
        {
            if (target == -1 && a[i - 1] > a[i])
            {
                target = a[i - 1];
            }
        }
    }
    if (target == -1)
    {
        target = *max_element(all(a));
    }
    for (int i : a)
    {
        if (i == target)
        {
            continue;
        }
        cout << i << ' ';
    }
    cout << endl;
}