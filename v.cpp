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
    rep(i, n)
    {
        cin >> a[i];
    }
    reverse(all(a));
    int now = 2;
    rep(i, n - 1)
    {
        // debug(now);
        int min_num = now;
        int max_num = now + a[i] - 1;
        // debug(min_num);
        // debug(max_num);
        if (max_num < a[i + 1])
        {
            cout << -1 << endl;
            return 0;
        }
        while(max_num % a[i+1] != 0){
            max_num--;
        }
        now = max_num;
    }
    // debug(now);
    cout << now << ' ' << now + a[n - 1] - 1 << endl;
}