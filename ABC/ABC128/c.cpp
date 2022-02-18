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

string binary_expression(int n, int d)
{
    string ans = "";
    rep(i, d) { ans.push_back((n >> i & 1) + '0'); }
    return ans;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> switches(n);
    rep(i, m)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int s;
            cin >> s;
            s--;
            switches[s] |= 1 << i;
        }
    }
    int target = 0;
    rep(i, m)
    {
        int p;
        cin >> p;
        target |= (p << i);
    }
    int ans = 0;
    rep(i, 1 << n)
    {
        int state = 0;
        rep(j, n)
        {
            if ((i >> j) & 1)
            {
                state ^= switches[j];
            }
        }
        if (state == target)
        {
            ans++;
        }
    }
    cout << ans << endl;
}