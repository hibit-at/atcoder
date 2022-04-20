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
    vector<pair<int, int>> vp(n);
    vector<int> rate(n);
    vector<int> org_rate(n);
    vector<int> org_hand(n);
    rep(i, n)
    {
        int r, h;
        cin >> r >> h;
        vp[i] = {r, h};
        rate[i] = r;
        org_rate[i] = r;
        org_hand[i] = h;
    }
    sort(all(vp));
    sort(all(rate));
    vector<vector<int>> hand_some(4, vector<int>(n + 1));
    rep(i, n)
    {
        hand_some[vp[i].second][i + 1] = 1;
    }
    rep1(hand, 3)
    {
        rep(i, n)
        {
            hand_some[hand][i + 1] += hand_some[hand][i];
        }
    }
    rep(i, n)
    {
        int win = 0;
        int lose = 0;
        int draw = -1;
        int h = org_hand[i];
        int r = org_rate[i];
        win += lower_bound(all(rate), r) - rate.begin();
        lose += rate.end() - upper_bound(all(rate), r);
        int lose_border = upper_bound(all(rate), r) - rate.begin();
        int span = lose_border - win;
        vector<int> span_sum(4);
        rep1(i, 3)
        {
            span_sum[i] = hand_some[i][lose_border] - hand_some[i][win];
        }
        if (h == 1)
        {
            win += span_sum[2];
            lose += span_sum[3];
            draw += span_sum[1];
        }
        if (h == 2)
        {
            win += span_sum[3];
            lose += span_sum[1];
            draw += span_sum[2];
        }
        if (h == 3)
        {
            win += span_sum[1];
            lose += span_sum[2];
            draw += span_sum[3];
        }
        cout << win << ' ' << lose << ' ' << draw << endl;
    }
}