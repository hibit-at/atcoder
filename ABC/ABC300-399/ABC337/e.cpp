#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int n;
  cin >> n;
  
  int b = 0;
  while((1<<b) < n) b++;
  cout << b << endl;
  
  for(int i = 0; i < b; i++){
    vector<int> avec;
    for(int j = 0; j < n; j++) if(j & (1<<i)) avec.push_back(j+1);
    cout << avec.size() << " ";
    for(auto a : avec) cout << a << " ";
    cout << endl;
  }
  
  string s;
  cin >> s;
  
  int ans = 0;
  for(int i = 0; i < b; i++) if(s[i] == '1') ans |= 1<<i;
  cout << ans+1 << endl;
  
  return 0;
}
