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

void print_queue(queue<ll> q)
{
    while (q.size() > 0)
    {
        ll now = q.front();
        q.pop();
        cout << now << ',';
    }
    cout << endl;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    queue<ll> q;
    rep(i, n)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    ll ans = 0;
    ll partsum = 0;
    queue<ll> worm;
    while (q.size() > 0)
    {
        ll now = q.front();
        q.pop();
        worm.push(now);
        partsum += now;
        if (worm.size() > k)
        {
            partsum -= worm.front();
            worm.pop();
        }
        if (worm.size() == k)
        {
            ans += partsum;
        }
    }
    cout << ans << endl;
}