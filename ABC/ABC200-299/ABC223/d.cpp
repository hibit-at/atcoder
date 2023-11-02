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

bool top_sort(int n, vector<vector<int>> to)
{
    vector<int> graph(n + 1);
    rep1(i, n)
    {
        for (int next : to[i])
        {
            graph[next]++;
        }
    }
    stack<int> st;
    rep1(i, n)
    {
        if (graph[i] == 0)
        {
            st.push(i);
        }
    }
    while (st.size() > 0)
    {
        int now = st.top();
        st.pop();
        for (int next : to[now])
        {
            graph[next]--;
            if (graph[next] == 0)
            {
                st.push(next);
            }
        }
    }
    rep1(i, n)
    {
        if (graph[i] > 0)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n + 1, vector<int>());
    vector<int> graph(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        graph[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    rep1(i, n)
    {
        if (graph[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (q.size() > 0)
    {
        int now = q.top();
        q.pop();
        ans.push_back(now);
        for (int next : to[now])
        {
            graph[next]--;
            if (graph[next] == 0)
            {
                q.push(next);
            }
        }
    }
    if (ans.size() != n)
    {
        cout << -1 << endl;
        return 0;
    }
    rep(i, n)
    {
        cout << ans[i];
        if (i < n - 1)
        {
            cout << ' ';
        }
        else
        {
            cout << endl;
        }
    }
}