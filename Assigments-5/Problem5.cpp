#include <bits/stdc++.h>
using namespace std;



int findsum(){
    int sum =0;
    return sum;
}

int main(){
    int N , M;
    cin >> N >> M;
     int arr[N][M];
     for(int i=0; i <N ;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
     }

     int value[N][M];

     for(int i=0; i <N ;i++){
        for(int j=0;j<M;j++){
            if(i-1 >= 0){
                value[i][j] = 0;
            }
        }
     }


}