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
#include <stack>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

void YesNo(bool b)
{
    if (b)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

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
    // print_vector(graph);
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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n + 1, vector<int>());
    rep(_, m)
    {
        int k;
        cin >> k;
        int last = -1;
        int now = -1;
        rep(i, k)
        {
            cin >> now;
            if (last != -1)
            {
                to[last].push_back(now);
            }
            last = now;
        }
    }
    YesNo(top_sort(n, to));
}