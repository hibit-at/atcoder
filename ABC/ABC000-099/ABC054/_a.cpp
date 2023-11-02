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
    int a, b;
    cin >> a >> b;
    auto poker = [](int x)
    {
        if (x == 1)
        {
            return 14;
        }
        return x;
    };
    if (poker(a) > poker(b))
    {
        cout << "Alice" << endl;
    }
    else if (poker(a) == poker(b))
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
}