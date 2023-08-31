#include <bits/stdc++.h>
using namespace std;

int main(){
    int D,P,W;
    cin >> D >> P >> W;
    int difficulty[D],profit[P],worker[W];  
    for(int i=0; i <D;i++){
        cin >> difficulty[i];
    }
    for(int i=0; i <D;i++){
        cin >> profit[i];
    }
    for(int i=0; i <D;i++){
        cin >> worker[i];
    }
    

    int maxprofit =0;
    for(int i=0;i<W;i++){
        int tempprofit =0;
        for(int j=0; j<D ;j++){
            if(worker[i] >= difficulty[j]){
                if(tempprofit < profit[j]){
                    tempprofit = profit[j];
                    
                }
            }
        }

        maxprofit += tempprofit;
    }
}