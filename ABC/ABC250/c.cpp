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
    int n, q;
    cin >> n >> q;
    vector<int> box_to_ball(n);
    vector<int> ball_to_box(n);
    rep(i, n)
    {
        box_to_ball[i] = i;
        ball_to_box[i] = i;
    }
    while (q--)
    {
        int target_ball;
        cin >> target_ball;
        target_ball--;
        // debug(target_ball);
        int target_box = ball_to_box[target_ball];
        // debug(target_box);
        int flap_box;
        if (target_box == n - 1)
        {
            flap_box = target_box - 1;
        }
        else
        {
            flap_box = target_box + 1;
        }
        // debug(flap_box);
        int flap_ball = box_to_ball[flap_box];
        // debug(flap_ball);
        swap(box_to_ball[target_box], box_to_ball[flap_box]);
        swap(ball_to_box[target_ball], ball_to_box[flap_ball]);
    }
    vector<int> ans(n);
    rep(i, n)
    {
        ans[i] = box_to_ball[i] + 1;
    }
    auto print_join = [](auto v)
    {
        int size = v.size();
        rep(i, size)
        {
            if (i < size - 1)
            {
                cout << v[i] << ' ';
            }
            else
            {
                cout << v[i] << endl;
            }
        }
    };
    print_join(ans);
}