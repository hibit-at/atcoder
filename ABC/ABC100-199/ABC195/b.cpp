#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

int main(){
    int a,b,w;
    cin >> a >> b >> w;
    vector<int> ans;
    for(int i=1;i<=(w*1000+a-1)/a;i++){
        double tmp = (double)w*1000/i;
        if(a<=tmp && tmp<=b){
            ans.push_back(i);
        }
    }
    if(ans.size()==0){
        cout << "UNSATISFIABLE" << endl;
    }else{
        cout << ans.front() << " " << ans.back() << endl;
    }
}