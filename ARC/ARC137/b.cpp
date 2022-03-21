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
    vector<int> a(n);
    map<int, int> mp;
    rep(i, n)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = -1;
        }
        if (i > 0)
        {
            a[i] += a[i - 1];
        }
        mp[a[i]]++;
    }
    print_vector(a);
    cout << mp.size() << endl;
}