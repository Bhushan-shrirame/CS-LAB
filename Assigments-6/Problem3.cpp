#include <bits/stdc++.h>
using namespace std;

int main(){
    int D,W;
    cin >> D >> W;
    int difficulty[D],profit[D],worker[W];  
    for(int i=0; i <D;i++){
        cin >> difficulty[i];
    }
    for(int i=0; i <D;i++){
        cin >> profit[i];
    }
    for(int i=0; i <W;i++){
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
    cout << " the maximum profit we can achieve after assigning the workers to the jobs is  " << maxprofit << endl;
}