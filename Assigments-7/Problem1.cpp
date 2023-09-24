#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') {
        return 0;
    }
    
    int n = s.size();
    vector<int> dp(n + 1, 0);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        
        int twoDigit = stoi(s.substr(i - 2, 2));
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    
    return dp[n];
}

int main() {
    string encoded_message ;
    cin >> encoded_message;
    int ways = numDecodings(encoded_message);
    cout << "Number of ways to decode: " << ways << endl;
    return 0;
}
