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
    int a, b;
    cin >> a >> b;
    queue<int> x, y, z;
    rep(i, n)
    {
        int p;
        cin >> p;
        if (p <= a)
        {
            x.push(p);
        }
        else if (p <= b)
        {
            y.push(p);
        }
        else
        {
            z.push(p);
        }
    }
    cout << min(min(x.size(), y.size()), z.size()) << endl;
}