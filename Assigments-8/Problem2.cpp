#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int fullprice = INT_MAX; 
        int price =0;
        int count=k;
        if(k==0){
            for(int i=0;i<flights.size(); i++){
                if(flights[i][0] == src && flights[i][1] == dst ){
                    return flights[i][2];
                }
            }
        }

        for(int i =0; i< flights.size();i++){
           if(flights[i][0] == 0){
               int next = flights[i][1];
               price = flights[i][2];
               for(int j=0;j<flights.size();j++){
                   if(next == flights[j][0] && flights[j][1] == dst){
                           fullprice = price + flights[j][2];
                           return fullprice;
                    }
                   if(next == flights[j][0]){
                       price += flights[j][2];
                       fullprice = min(fullprice , price);
                       next = flights[j][1];
                       count--;
                   }
                   if(count == 0 && flights[j][1] != dst){
                       count++;
                       next = flights[j][0];
                       price -= flights[j][2];
                       fullprice = min(fullprice , price);
                   }
               }
           }
           
        }
        cout << fullprice << endl; 
        return fullprice;
        
    }
};


int main() {

    Solution s;
    int n , src, dst , k;
    cin >> n >> src >>dst >> k;
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

     cout  << "the cheapest price from " << src <<" to " << dst << " with at most "<< k <<" stops."<< s.findCheapestPrice( n ,v , src ,dst , k) << endl;

   return 0;
}

