#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    int cnt = 0;
    int temp = 0;
    for(int i = 0;i < S.length();i++){
        if(S[i]== '#'){
            cnt++;
            if(cnt == 1){
                temp = i;
            }else{
                cout << temp + 1 << ',' << i + 1 << "\n";
                cnt = 0;
            }
        }
    }

    return 0;
}