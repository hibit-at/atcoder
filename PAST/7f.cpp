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
    int n;
    cin >> n;
    int lim = 24 * 1e5 + 10;
    vector<int> imos(lim);
    rep(i, n)
    {
        int d, s, t;
        cin >> d >> s >> t;
        d--;
        s += d * 24;
        t += d * 24;
        imos[s]++;
        imos[t]--;
    }
    vector<int> IMOS(lim + 1);
    rep1(i, lim)
    {
        IMOS[i] = imos[i - 1] + IMOS[i - 1];
        if (IMOS[i] > 1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}