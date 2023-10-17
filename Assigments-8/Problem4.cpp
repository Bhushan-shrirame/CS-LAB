#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int res = values[0];
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector<int> visited(n, 0);
        dfs(graph, values, visited, res, 0, 0, 0, maxTime);
        cout << "The maximum quality of a valid path: "<< res << endl;
        return res;
    }
    
    void dfs(vector<vector<pair<int,int>>>& graph, vector<int>& values, vector<int>& visited, int& res, int node, int score, int time, int& maxTime)
    {
        if(time > maxTime)
            return;
        
        if(visited[node] == 0)
            score += values[node];
        
        visited[node]++;
		
      
        if(node == 0)
            res = max(res, score);
        
        for(auto it : graph[node])
        {
            int neigh = it.first;
            int newTime = time + it.second;
            dfs(graph, values, visited, res, neigh, score, newTime, maxTime);
        }
        
        visited[node]--;
    }
};


int main() {

    Solution s;
    vector<int> values;
    int vsize , b;
    cin >> vsize;
    for(int i=0; i<vsize; i++){
        cin >> b;
        values.push_back(b); 
    }
    vector<vector<int>> v;
    int row, column, a;
    cin>>row >> column;
    for(int i=0 ; i<row ; i++) {
         vector<int> p;
         for(int j=0 ; j<column ; j++) {
              cin>>a;
              p.push_back(a);
         }
         v.push_back(p);
    }
    int maxtime;
    cin >> maxtime;

    s.maximalPathQuality(values ,v , maxtime);

   return 0;
}