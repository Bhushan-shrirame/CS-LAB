#include <bits/stdc++.h>
using namespace std;

class solution{
public:

   vector<float>ans;
   float findmedian(vector<float> arr){
    sort(arr.begin() , arr.end());
    int n = arr.size();
    int m = n/2;
    if(n%2 !=0){
        return arr[m]; 
    }
    return ((arr[m -1] + arr[m]) / 2);
   }

   vector<float> medianarray(vector<int> nums , int k){
    int n = nums.size();
    for(int i =0;i<n-(k-1);i++){
        vector<float> arr;
        for(int j=i;j<i+k;j++){
            arr.push_back(nums[j]);
        }
        ans.push_back(findmedian(arr));
        arr.clear();
    }
    int m = ans.size();
    for(int i=0;i<m;i++){
        cout<< ans[i] << " ";
    }
    cout << endl;
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