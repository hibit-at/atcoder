
#include <iostream>

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
    ll n, k;
    cin >> n >> k;
    scc_graph graph(n);
    vector<int> a(n);
    vector<ll> loop(n, -1);
    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
        graph.add_edge(i, a[i]);
        if (i == a[i])
        {
            loop[i] = 1;
        }
    }
    vector<vector<int>> scc = graph.scc();
    for (auto v : scc)
    {
        if (v.size() == 1)
        {
            continue;
        }
        for (int i : v)
        {
            loop[i] = v.size();
        }
    }
    int pos = 0;
    while (k--)
    {
        pos = a[pos];
        if (loop[pos] > -1)
        {
            k %= loop[pos];
        }
    }
    cout << pos + 1 << endl;
}