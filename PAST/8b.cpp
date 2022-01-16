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

int main(void){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<int> b(m);
    rep(i,m){
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    rep(i,n){
        rep(j,m){
            if(a[i] == b[j]){
                cout << a[i] << ' ';
            }
        }
    }
}