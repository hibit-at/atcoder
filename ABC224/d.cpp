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

void print_to(vector<vector<int>> to)
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

vector<vector<int>> to(10);

int dfs(int from, vector<int> pos, vector<bool> seen)
{
    int ans = 1;
    for (auto next : to[from])
    {
        debug(next);
        vector<int> next_pos = pos;
        next_pos[from] = pos[next];
        dfs(next, next_pos,)
    }
    return ans;
}

int main(void)
{
    int m;
    cin >> m;
    rep(i, m)
    {
        int v, u;
        cin >> v >> u;
        to[v].push_back(u);
        to[u].push_back(v);
    }
    print_to(to);
    vector<int> pos(10);
    rep1(i, 8)
    {
        int p;
        cin >> p;
        pos[p] = i;
    }
    print_vector<int>(pos);
    vector<bool> seen(10, false);
    dfs(1, pos, seen);
}