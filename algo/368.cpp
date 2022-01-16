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
	double n;
	cin >> n;
	double ng = 0;
	double ok = 101;
	while (abs(ng - ok) > 0.00001)
	{
		double mid = (ng + ok) / 2;
		double res = mid * (mid * (mid + 1) + 2) + 3;
		if(res >= n){
			ok = mid;
		}else{
			ng = mid;
		}
	}
	cout << setprecision(20) << ok << endl;
}