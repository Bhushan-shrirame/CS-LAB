#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    
    int peak=0, bottom1 = 0, bottom2=0 , mls=0, maxmls = 0;
       
       if(arr[0] >= arr[1]){
        bottom1 = 1;
       }

    for(int i=1;i <n-1; i++){
        if((arr[i] >= arr[i-1] ) && (arr[i] >= arr[i+1])){
            peak = i;
        }
        if(arr[i] <= arr[i+1] && peak){
            bottom2 = i;
            mls = bottom2 - bottom1 + 1;
             if(arr[i] < arr[i+1]){
                bottom1 = i;
             }
             if(arr[i] == arr[i+1]){
                bottom1 = i+1; 
             }
            peak = 0;
        }
        if(maxmls < mls){
            maxmls = mls;
        }
    }
    if (bottom2 < peak){
        bottom2 = n-1;
        mls = bottom2 - bottom1 + 1;
        if(maxmls < mls){
            maxmls = mls;
        }
    }
       if(maxmls <=2 ){
        return 0;
       }
    cout << "The maximum length of a subsequence of the array is "<<  maxmls << endl;
}