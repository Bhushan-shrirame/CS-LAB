#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int solve(vector<int> &nums,int target,int ans,int index)
    {
        if(index==nums.size()&&ans==target)
          return 1;
        if(index>=nums.size())
          return 0;

        return solve(nums,target,ans+nums[index],index+1)+solve(nums,target,ans-nums[index],index+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0,i=0;
        return solve(nums,target,ans,i);
    }
};

int main(){
    Solution sol;
    int ans , t;
    cin >> t;
    while(t--){
        vector<int> nums;
        int c , target;
        cin >> c;
        while(c--){
            int a;
            cin >>a;
            nums.push_back(a);
        }
        cin >> target;
        ans = sol.findTargetSumWays(nums , target);
        cout << " The number of different expressions that can build, which evaluates to the target is: "<< ans << endl;
    }
    return ans;
}