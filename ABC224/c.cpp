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
#include <stack>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ll x1 = x[i];
                ll y1 = y[i];
                ll x2 = x[j];
                ll y2 = y[j];
                ll x3 = x[k];
                ll y3 = y[k];
                x2 -= x1;
                y2 -= y1;
                x3 -= x1;
                y3 -= y1;
                if(y3*x2 != y2*x3){
                    ans ++;
                }
            }
        }
    }
    cout << ans << endl;
}