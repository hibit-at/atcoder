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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> AB(n + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> CD(n + 1, vector<bool>(n + 1, false));
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        AB[a][b] = true;
        AB[b][a] = true;
    }
    rep(i, m)
    {
        int c, d;
        cin >> c >> d;
        CD[c][d] = true;
        CD[d][c] = true;
    }
    vector<int> p(n + 1);
    rep1(i, n)
    {
        p[i] = i;
    }
    do
    {
        bool ok = true;
        rep1(i, n)
        {
            rep1(j, n)
            {
                if (AB[i][j] != CD[p[i]][p[j]])
                {
                    ok = false;
                }
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(p.begin() + 1, p.end()));
    cout << "No" << endl;
}