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
    int n, a, b;
    cin >> n >> a >> b;
    rep(i, a * n)
    {
        rep(j, b * n)
        {
            bool sub1 = (i / a) % 2;
            bool sub2 = (j / b) % 2;
            if (sub1 ^ sub2)
            {
                cout << '#';
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
    }
}