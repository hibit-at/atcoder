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
    int a, b;
    cin >> a >> b;
    vector<int> ans;
    int sum = 0;
    if (a >= b)
    {
        rep1(i, a)
        {
            ans.push_back(i);
            sum += i;
        }
        rep1(i, b - 1)
        {
            ans.push_back(-i);
            sum -= i;
        }
        ans.push_back(-sum);
    }
    else
    {
        rep1(i, b)
        {
            ans.push_back(-i);
            sum -= i;
        }
        rep1(i, a - 1)
        {
            ans.push_back(i);
            sum += i;
        }
        ans.push_back(-sum);
    }
    int n = ans.size();
    rep(i, n)
    {
        cout << ans[i];
        if (i < n - 1)
        {
            cout << ' ';
        }
        else
        {
            cout << endl;
        }
        ans.push_back(-sum);
    }
}