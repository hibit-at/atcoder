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

const int inf = 1e9;

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
        cout << i << ',';
    }
    cout << endl;
    return;
}

int main(void)
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> to(n + 1);
    rep(i, q)
    {
        int L, R;
        cin >> L >> R;
        L--;
        to[L].push_back(R);
        to[R].push_back(L);
    }
    auto dist = bfs(n, to, 0);
    if (dist[n] < inf)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}