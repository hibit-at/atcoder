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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

const int inf = 1e9;


int main()
{
    int n;
    cin >> n;
    vector<int> buc(n + 1, inf);
    buc[0] = 0;
    buc[1] = 1;
    queue<int> q;
    q.push(1);
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        int cost = buc[now];
        int next = now + 1;
        if (cost + 1 < buc[next])
        {
            buc[next] = cost + 1;
            q.push(next);
        }
        next = now * 3;
        if (next > n)
        {
            continue;
        }
        if (cost + 1 < buc[next])
        {
            buc[next] = cost + 1;
            q.push(next);
        }
    }
    cout << buc[n] << endl;
}