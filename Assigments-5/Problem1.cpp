#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int prices[n];
    for(int i = 0;i < n;i++){
        cin >> prices[i];
    }
    int res = 0;
        int minimum = prices[0];
        for(int i =0; i<n; i++){
            if(prices[i] < minimum){
                minimum = prices[i];
            }
            if(res < (prices[i] - minimum)){
                res = prices[i] - minimum;
            }
        }
        cout << "Max profit " << res << endl;
}