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

#include <atcoder/scc>
using namespace atcoder;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n, vector<int>(0));
    scc_graph graph(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph.add_edge(a, b);
    }
    auto scc = graph.scc();
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        }
    };
    cout << scc.size() << endl;
    // print_vector_vector(scc);
    for (auto v : scc)
    {
        cout << v.size() << ' ';
        auto print_join = [](auto v)
        {
            int size = v.size();
            rep(i, size)
            {
                if (i < size - 1)
                {
                    cout << v[i] << ' ';
                }
                else
                {
                    cout << v[i] << endl;
                }
            }
        };
        print_join(v);
    }
}