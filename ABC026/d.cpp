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

double a,b,c;

const double PI=3.14159265358979323846;

double f(double t){
    return a*t+b*sin(c*t*PI);
}

int main(void){
    cin >> a >> b >> c;
    double left = 0;
    double right = 1e18;
    while(abs(left-right)>1e-7){
        double mid = (left+right)/2;
        double dist = f(mid);
        if(abs(dist-100)<1e-7){
            cout << mid << endl;
            return 0;
        }else if(dist > 100){
            right = mid;
        }else{
            left = mid;
        }
    }
    cout << setprecision(20) << right << endl;
}