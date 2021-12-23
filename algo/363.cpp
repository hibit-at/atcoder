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
	int n;
	cin >> n;
	vector<pair<int, int>> vp(n);
	rep(i, n)
	{
		int s, t;
		cin >> s >> t;
		vp[i] = {t, s};
	}
	sort(all(vp));
	int time = 0;
	int ans = 0;
	rep(i, n)
	{
		int end = vp[i].first;
		int start = vp[i].second;
		if (time > start)
		{
			continue;
		}
		time = end;
		ans++;
	}
	cout << ans << endl;
}