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
    int n, m;
    ;
    cin >> n >> m;
    vector<int> graph(n);
    vector<vector<int>> to(n, vector<int>(0));
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        graph[v]++;
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    print_vector(graph);
    stack<int> q;
    rep(i, n)
    {
        if (graph[i] == 0)
        {
            q.push(i);
        }
    }
    auto print_front = [](auto q)
    {
        while (q.size() > 0)
        {
            cout << q.front() << ',';
            q.pop();
        }
        cout << endl;
    };
    vector<int> ans(0);
    // print_front(q);
    while (q.size())
    {
        int now = q.top();
        ans.push_back(now);
        q.pop();
        for (int next : to[now])
        {
            graph[next]--;
            if (graph[next] == 0)
            {
                q.push(next);
                // print_front(q);
            }
        }
    }
    print_vector(ans);
}