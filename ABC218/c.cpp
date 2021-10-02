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

void print_set(set<pair<int, int>> s)
{
    for (auto p : s)
    {
        cout << p.first << "," << p.second << endl;
    }
}

set<pair<int,int>> rotate(set<pair<int,int>> s){
    set<pair<int,int>> ans;
    for(auto p : s){
        int x = p.first;
        int y = p.second;
        ans.insert({-y, x});
    }
    set<pair<int,int>> ans2;
    for(auto p : ans){
        int x = p.first - (*ans.begin()).first;
        int y = p.second - (*ans.begin()).second;
        ans2.insert({x,y});
    }
    return ans2;
}

int main(void)
{
    int n;
    cin >> n;
    set<pair<int, int>> set_s;
    int off_x = -1, off_y = -1;
    rep(i, n)
    {
        rep(j, n)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                if(off_x == -1){
                    off_x = i;
                    off_y = j;
                }
                set_s.insert({i-off_x,j-off_y});
            }
        }
    }
    // print_set(set_s);
    set<pair<int, int>> set_t;
    rep(i,n){
        rep(j,n){
            char c;
            cin >> c;
            if(c == '#'){
                set_t.insert({i,j});
            }
        }
    }
    rep(i,4){
        // print_set(set_t);
        set_t = rotate(set_t);
        if(set_s == set_t){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}