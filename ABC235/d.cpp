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

int change(int n)
{
    if (n < 10)
    {
        return n;
    }
    if (n % 10 == 0)
    {
        return n;
    }
    string s = to_string(n);
    char back = s.back();
    s.pop_back();
    string t = back + s;
    return stoi(t);
}

int main(void)
{
    int a, n;
    cin >> a >> n;
    vector<int> dist(1e6, 1e6);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        int next = change(now);
        if (dist[now] + 1 < dist[next])
        {
            dist[next] = dist[now] + 1;
            q.push(next);
        }
        if (now >= 1e6 / a)
        {
            continue;
        }
        next = now * a;
        if (dist[now] + 1 < dist[next])
        {
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
    if (dist[n] == 1e6)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[n] << endl;
    }
}