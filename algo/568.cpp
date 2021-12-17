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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main()
{
	ll n, m, a = 0, b = 0;
	cin >> n >> m;
	rep(i, n)
	{
		ll x;
		cin >> x;
		a += x;
	}
	rep(i, m)
	{
		ll x;
		cin >> x;
		b += x;
	}
	cout << m * a + n * b << endl;
}