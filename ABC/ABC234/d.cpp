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
    int n, k;
    cin >> n >> k;
    queue<int> q;
    rep(i, n)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, k)
    {
        int front = q.front();
        q.pop();
        pq.push(front);
    }
    cout << pq.top() << endl;
    rep(i, n - k)
    {
        int front = q.front();
        q.pop();
        pq.push(front);
        pq.pop();
        cout << pq.top() << endl;
    }
}