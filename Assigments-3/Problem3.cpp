#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(vector<vector<int>> &adj, int v, vector<int> &visited){
        visited[v] = 1;
        for(int i=0;i<adj[v].size();i++){
            if(adj[v][i] == 1 && !visited[i]){
                    dfs(adj, i, visited);
            }
        }
    }
  
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> visited(V, 0);
        int count = 0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};


int main(){
    int V, x;
    cin >> V;

    vector<vector<int>>adj;
    for(int i=0; i < V; i++){
       vector<int> temp;
       for(int j=0;j<V;j++){
        cin >>x;
        temp.push_back(x);

       }
       adj.push_back(temp);
    }

    Solution ob;
    cout << "The total number of provinces: "<< ob.numProvinces(adj, V) << endl;
}

