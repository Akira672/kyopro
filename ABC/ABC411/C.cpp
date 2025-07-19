#include<bits/stdc++.h>
using namespace std;

#define BLACK 1
#define WHITE 0

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<int>A(N+2,WHITE);//両端は常に白とする
    int ans = 0;
    while(Q--){
        int An;
        cin >> An;
        if(A[An] == WHITE){
            if(A[An - 1] == WHITE && A[An + 1] == WHITE){
                ans++;//白白白→白黒白　増える
            }else if(A[An - 1] == BLACK && A[An + 1] == BLACK){
                ans--;//黒白黒→黒黒黒　2つの黒がつながるため黒の区間数は減る
            }
            A[An] = BLACK;
        }else{
            if(A[An - 1] == WHITE && A[An + 1] == WHITE){
                ans--;//白黒白→白白白　白が減る
            }else if(A[An - 1] == BLACK && A[An + 1] == BLACK){
                ans++;//黒黒黒→黒白黒　黒が2つに分割されるため黒の区間数が増える
            }
            A[An] = WHITE;
        }
        cout << ans << "\n";
    }
  return 0;
}