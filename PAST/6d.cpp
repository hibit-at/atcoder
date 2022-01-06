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


int main(void) {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<ll> s(n+1);
    rep1(i,n){
        s[i] = a[i-1] + s[i-1];
    }
    rep(i,n-k+1){
        cout << s[i+k] - s[i] << endl;
    }
}