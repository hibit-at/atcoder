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
    int a, b, k;
    cin >> a >> b >> k;
    priority_queue<int> q;
    rep1(i, 100)
    {
        if (a % i == 0 && b % i == 0)
        {
            q.push(i);
        }
    }
    k--;
    while (k--)
    {
        q.pop();
    }
    cout << q.top() << endl;
}