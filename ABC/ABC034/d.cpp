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
    int n, k;
    cin >> n >> k;
    vector<double> w(n), p(n);
    rep(i, n)
    {
        cin >> w[i] >> p[i];
    }
    double ok = 0;   // 0%には絶対できる
    double ng = 100; // 100%より上には絶対できない
    while (abs(ok - ng) > 1e-8)
    {
        double target = ok + ng;
        target /= 2;
        vector<double> salt(n, 0);
        rep(i, n)
        {
            salt[i] = p[i] - target;
            salt[i] /= 100;
            salt[i] *= w[i];
        }
        // debug(target);
        // print_vector(salt);
        sort(all(salt));
        reverse(all(salt));
        double criterion = 0;
        rep(i,k){
            criterion += salt[i];
        }
        // debug(criterion);
        if (criterion >= 0)
        {
            ok = target;
        }
        else
        {
            ng = target;
        }
    }
    cout << setprecision(20) << ok << endl;
}