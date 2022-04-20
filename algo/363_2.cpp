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
	vector<pair<int, int>> sche(n);
	rep(i, n)
	{
		int s, t;
		cin >> s >> t;
		sche[i] = {t, s};
	}
	sort(all(sche));
	auto print_vector_pair = [](auto v)
	{
		for (auto i : v)
		{
			cout << "(" << i.first << "," << i.second << ")"
				 << " ";
		}
		cout << endl;
	};
	print_vector_pair(sche);
	int pos = 0;
	int ans = 0;
	while (pos <= sche.back().second)
	{
		pos = sche.front().second;
		pos++;
	}
}