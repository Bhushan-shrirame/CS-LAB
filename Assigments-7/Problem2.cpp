#include <bits/stdc++.h>
using namespace std;


int maxinsorted(int arrs[] , int N , int M){
    int count =0 ,sum =0;
    for(int i=0;i<N;i++){
        sum += arrs[i];
        if(sum <= M){
            count++;
        }
    }
    return count;
}
int maxinumsorted(int arrus[], int N , int M){
    int count =0 ,sum =0;
    for(int i=0;i<N;i++){
        sum += arrus[i];
        if(sum > M){
            sum -= arrus[i];
        }
        if(sum <= M){
            count++;
        }
    }
    return count;
}



int main(){
    int N,M;
    cin >> N;
    cin >> M;

    int arrs[N],arrus[N];
    
    for(int i=0; i<N;i++){
        cin >> arrs[i];
        arrus[i] = arrs[i];
    }
    

    sort(arrs,arrs +N);

    cout << "maximum number of elements in sorted is" << maxinsorted(arrs ,N ,M) << endl;
    cout << "maximum number of elements in unsorted is " << maxinumsorted(arrus ,N ,M) << endl;

    return 0;
}

int main(){
    int N,M;
    cin >> N;
    cin >> M;

    int arrs[N],arrus[N];
    
    for(int i=0; i<N;i++){
        cin >> arrs[i];
        arrus[i] = arrs[i];
    }
    

    sort(arrs,arrs +N);

    cout << "maximum number of elements in sorted is" << maxinsorted(arrs ,N ,M) << endl;
    cout << "maximum number of elements in unsorted is " << maxinumsorted(arrus ,N ,M) << endl;

    return 0;
}