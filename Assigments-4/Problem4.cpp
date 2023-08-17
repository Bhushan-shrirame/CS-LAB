#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    
    int peak=0, bottom1 = arr[0], bottom2 , mls;
   
    for(int i=0;i <n; i++){
       if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
        peak = i;
       }
       if(arr[i] < arr[i+1] && peak){
          bottom2 = i;
          mls = max(peak - bottom1, bottom2 - peak);
          bottom1 = i+1;
          peak = 0;
       }
       
    }
    cout << "The maximum length of a subsequence of the array is "<<  mls << endl;
}