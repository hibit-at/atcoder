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
    ll a, b;
    cin >> a >> b;
    vector<bool> a_bit(32), b_bit(32);
    int pos = 0;
    while (a > 0)
    {
        a_bit[pos] = a % 2;
        a /= 2;
        pos++;
    }
    pos = 0;
    while (b > 0)
    {
        b_bit[pos] = b % 2;
        b /= 2;
        pos++;
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // print_vector(a_bit);
    // print_vector(b_bit);
    while (a_bit.back() == 0 && b_bit.back() == 0)
    {
        if (a_bit.size() == 0)
        {
            cout << 1 << endl;
            return 0;
        }
        a_bit.pop_back();
        b_bit.pop_back();
    }
    // print_vector(a_bit);
    // print_vector(b_bit);
    int ans = 0;
    while (a_bit.back() == b_bit.back())
    {
        if (a_bit.size() == 0)
        {
            break;
        }
        a_bit.pop_back();
        b_bit.pop_back();
        ans++;
    }
    cout << ans << endl;
}