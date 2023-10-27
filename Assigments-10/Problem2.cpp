#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int idx, int n){
        if(idx == special.size()){
            int temp = 0;
            for(int i=0; i<n; i++){
                temp += (needs[i] * price[i]);
            }
            return temp;
        }

        int flag = 0;
        for(int i=0; i<n; i++){
            if(special[idx][i] > needs[i]) flag = 1;
        }


        if(flag == 0){
            for(int i=0; i<n; i++){
                needs[i] -= special[idx][i];
            }
            int consider = special[idx][n] + solve(price, special,needs,idx,n);
            for(int i=0; i<n; i++){
                needs[i] += special[idx][i];
            }
            return min(consider, solve(price, special,needs,idx+1,n));
        }

        return solve(price, special,needs,idx+1,n);;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int ans = solve(price,special,needs,0,n);
        return ans;
    }
};

int main(){
    Solution sol;
    int t , ans;
    // cin >> t;
    // while(t--){
        int p,s1,s2,n;
        cin >> p >> s1 >> s2 >> n;
        vector<int> price,need;
        vector<vector<int>> special;
        while(p--){
            int pa;
            cin >> pa;
            price.push_back(pa);
        }
        for(int i=0;i<s1;i++){
            vector<int> spe;
            for(int j=0;j<s2;j++){
                int sp;
                cin >>sp;
                spe.push_back(sp);
            }
            special.push_back(spe);
        }
        while(n--){
            int pa;
            cin >> pa;
            need.push_back(pa);
        }
        ans = sol.shoppingOffers(price, special, need);
        cout << "OUTPUT" << ans << endl;
    // }
    return 0;
}