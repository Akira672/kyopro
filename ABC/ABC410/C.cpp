#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0;i < N;i++){
        A[i] = i + 1;
    }

    int P = 0;

    while(Q--){
        int op;
        cin >> op;
        switch(op){
            case 1:{
                int p,x;
                cin >> p >> x;
                p--;
                A[(P + p) % N] = x;
                break;
            }
            case 2:{
                int p;
                cin >> p;
                p--;
                cout << A[(P + p) % N] << "\n";
                break;
            }
            case 3:{
                int k;
                cin >> k;
                P = (P + k) % N;
                break;
            }
        }
    }

    return 0;
}