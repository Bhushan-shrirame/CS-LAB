#include <bits/stdc++.h>
using namespace std;

class solution{
public:
   
   vector<int>ans;

   int findmedian(vector<int> arr){
    sort(arr.begin() , arr.end());

   }

   vector<int> medianarray(vector<int> nums , int k){
    int n = nums.size();
    for(int i =0;i<n;i++){
        vector<int> arr;
        int b;
        for(int j=i;j<i+k-1;j++){
            cin >> b;
            arr.push_back(b);
        }
        ans.push_back(findmedian(arr));
        arr.clear();
    }
    return ans;
   }
};




int main(){
    solution s;
    int n ,a ,k;
    cin >> n;
    vector<int> nums;
    for(int i=0; i< n; i++){
        cin >> a;
        nums.push_back(a);
    }
    cin >>k;
    s.medianarray(nums , k);
}