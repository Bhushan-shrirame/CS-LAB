#include<bits/stdc++.h>
using namespace std;

class Solution { 
public:
    vector<int>ans; 
    bool backtrack(string s,int start){  
        if(start==s.size() and ans.size()>2)return true; 
        long long n=0; 
        for(int i=start;i<s.size();i++){ 
            n=n*10+s[i]-'0';    
            if(n<0 or n>INT_MAX)return false;  
            if(ans.size()<2|| (long long)ans.back()+(long long)ans[ans.size()-2]==n){
                ans.push_back(n);
                if(backtrack(s,i+1))return true; 
                ans.pop_back();
            }
            if(s[i]=='0' and i==start)return false;
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string s) {
        backtrack(s,0);
        return ans;
    }    
};

int main() {
    Solution solution;
    string num = "123456579";
    vector<int> result = solution.splitIntoFibonacci(num);

    if (!result.empty()) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "Cannot split the string into a Fibonacci-like sequence." << endl;
    }

    return 0;
}