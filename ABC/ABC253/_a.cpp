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
    int h, w;
    cin >> h >> w;
    vector<int> x(0);
    vector<int> y(0);
    rep(i, h)
    {
        string s;
        cin >> s;
        rep(j, w)
        {
            char c = s[j];
            if (c == 'o')
            {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    print_vector(x);
    print_vector(y);
}