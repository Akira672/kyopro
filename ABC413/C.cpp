#include<bits/stdc++.h>
using namespace std;

int main(){
  int Q;
  cin >> Q;
  
  queue<pair<long long,long long>> A;
  
  while(Q--){
    int t;
    cin >> t;
    
    if(t == 1){
      long long c,x;
      cin >> c >> x;
      A.push({c,x});
    }else{
      long long k;
      cin >> k;
      long long sum = 0;
      
      while(0 < k){
        
        auto [cnt,val] = A.front();
        
        if(cnt <= k){
          sum += cnt * val;
          k -= cnt;
          A.pop();
        }else{
          sum += k * val;
          A.front().first = cnt - k;
          break;
        }
      }
      
      cout << sum << "\n";
      
    }
  }
  return 0;
}