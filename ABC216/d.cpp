#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

void print_vector(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<int> graph(n + 1);
    rep(i, m)
    {
        int k;
        cin >> k;
        vector<int> a(k);
        rep(j, k)
        {
            int x;
            cin >> x;
            a[j] = x;
        }
        rep(j, k - 1)
        {
            graph[a[j]] = a[j + 1];
        }
    }
    // print_vector(graph);
    vector<bool> seen(n + 1);
    rep1(i, n)
    {
        if (seen[i])
        {
            continue;
        }
        queue<int> q;
        q.push(i);
        while (q.size())
        {
            int now = q.front();
            q.pop();
            // cout << "start from " << i << " now is " << now << endl;
            seen[now] = true;
            int next = graph[now];
            if (next == 0)
            {
                continue;
            }
            if (seen[next])
            {
                cout << "No" << endl;
                return 0;
            }
            q.push(next);
        }
    }
    cout << "Yes" << endl;
}