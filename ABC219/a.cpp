#include <algorithm>
#include <iostream>
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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

int main(void)
{
    int x;
    cin >> x;
    vector<int> scores = {40, 70, 90};
    rep(i, 3)
    {
        if (x < scores[i])
        {
            cout << scores[i] - x << endl;
            return 0;
        }
    }
    cout << "expert" << endl;
}