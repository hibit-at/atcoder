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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll a_size = n / a;
    ll a_sum = a * (a_size) * (a_size + 1) / 2;
    ll b_size = n / b;
    ll b_sum = b * (b_size) * (b_size + 1) / 2;
    ll ab_size = n / lcm(a, b);
    ll ab_sum = lcm(a, b) * (ab_size) * (ab_size + 1) / 2;
    cout << n * (n + 1) / 2 - a_sum - b_sum + ab_sum << endl;
}