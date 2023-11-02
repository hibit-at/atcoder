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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    rep1(i, n)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    rep1(i, n)
    {
        mp[i].push_back(0);
        mp[i].push_back(n+1);
        sort(all(mp[i]));
    }
    int q;
    cin >> q;
    while (q--)
    {
        int L, R, x;
        cin >> L >> R >> x;
        auto print_vector = [](auto v)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        };
        // print_vector(mp[x]);
        int dist = upper_bound(all(mp[x]), R) - lower_bound(all(mp[x]), L);
        // debug(dist);
        cout << dist << endl;
    }
}