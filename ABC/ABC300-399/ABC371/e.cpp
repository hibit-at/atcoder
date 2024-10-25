#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    // 値の最大値を取得
    int max_val = *max_element(a.begin(), a.end());
    // -1 で初期化
    vector<ll> last_occurrence(max_val + 1, -1);
    
    ll total = 0;
    for(ll i = 0; i < n; ++i){
        ll prev = last_occurrence[a[i]];
        ll contribution = (i - prev) * (n - i);
        total += contribution;
        last_occurrence[a[i]] = i;
    }
    
    cout << total;
}