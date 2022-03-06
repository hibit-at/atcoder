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
    int m;
    cin >> m;
    vector<vector<int>> to(10, vector<int>());
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    string s = "x999999999"; // どのコマがどこにいるか？
    rep1(i, 8)
    {
        int p;
        cin >> p;
        s[p] = i + '0';
    }
    queue<string> q;
    q.push(s);
    map<string, int> mp;
    mp[s] = 0;
    while (q.size() > 0)
    {
        string s = q.front();
        q.pop();
        int next = -1;
        rep1(i, 9)
        {
            if (s[i] == '9')
            {
                next = i;
            }
        }
        if(next == -1){
            continue;
        }
        for (int from : to[next])
        {
            string t = s;
            swap(t[from], t[next]);
            if (mp.count(t))
            {
                continue;
            }
            mp[t] = mp[s] + 1;
            q.push(t);
        }
    }
    string goal = "x123456789";
    if (mp.count(goal) == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mp[goal] << endl;
    }
}