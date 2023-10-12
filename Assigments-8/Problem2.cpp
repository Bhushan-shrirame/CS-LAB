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
        return fullprice;
        
    }
};

