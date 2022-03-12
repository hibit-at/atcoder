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
void print_join(vector<T> v)
{
    int n = v.size();
    rep(i, n)
    {
        cout << v[i];
        if (i < n - 1)
        {
            cout << ' ';
        }
        else
        {
            cout << endl;
        }
    }
}

int main(void)
{
    vector<int> a(3);
    rep(i,3){
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    print_join(a);
}