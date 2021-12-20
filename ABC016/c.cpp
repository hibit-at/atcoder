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

const int inf = 1e9;

template <typename T>
void print_to(vector<vector<T>> to)
{
    int n = to.size();
    rep(i, n)
    {
        cout << "from " << i << " : to ";
        for (int next : to[i])
        {
            cout << next << ",";
        }
        cout << endl;
    }
}

vector<int> bfs(int n, vector<vector<int>> to, int start)
{
    vector<int> dist(n + 1, inf);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (q.size() > 0)
    {
        int now = q.front();
        q.pop();
        for (int next : to[now])
        {
            if (dist[next] <= dist[now] + 1)
            {
                continue;
            }
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
    return dist;
}

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    return;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n + 1, vector<int>());
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    // print_to<int>(to);
    rep1(i, n)
    {
        vector<int> dist = bfs(n, to, i);
        // print_vector(dist);
        int ans = 0;
        rep1(j, n)
        {
            if (dist[j] == 2)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}