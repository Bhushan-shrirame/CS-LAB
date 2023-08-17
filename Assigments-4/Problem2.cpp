#include <bits/stdc++.h>
using namespace std;

int main(){
   int n, m;
   cin >> n >> m;
   int arr[n][m];
   int visited[n][m];
    
  for(int i=0; i < n; i++){
    for(int j=0;j<m;j++){
        cin >> arr[i][j];
        visited[i][j] =0;
    }
  }

  visited[0][0] =1;
  for(int i=0; i < n; i++){
    for(int j=0;j<m;j++){
        

        if (arr[i][j]) continue;
            if (j + 1 < m)
                if (!arr[i][j + 1])
                    visited[i][j + 1] += visited[i][j];
            if (i + 1 < n)
                if (!arr[i + 1][j])
                    visited[i + 1][j] += visited[i][j];
    }
  }

  cout << visited[n-1][m-1] << endl;
}