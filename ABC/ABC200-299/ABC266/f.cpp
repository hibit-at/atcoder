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
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

#include <atcoder/scc>
using namespace atcoder;

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> to(n, vector<int>());
    scc_graph graph(n);
    rep(i, n)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        debug(u);
        debug(v);
        graph.add_edge(u, v);
        graph.add_edge(v, u);
    }
    auto scc = graph.scc();
    for(auto v : scc){
        auto print_vector = [](auto v)
        {
            int size = v.size();
            int cnt = 1;
            for (auto i : v)
            {
                cout << i;
                if (cnt < size)
                {
                    cout << " ";
                }
                else
                {
                    cout << endl;
                }
                cnt++;
            }
        };
        print_vector(v);
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
    }
}