#include<bits/stdc++.h>
using namespace std;

int maxUnique(string S ,set<string> &st )
{ 
    int stringmax = 0;
    for (int i = 1; i <= S.length(); i++)
    {
    	string temp = S.substr(0, i);
    	if (st.find(temp) == st.end())
    	{
    	st.insert(temp);
    	stringmax = max(stringmax, maxUnique(S.substr(i), st) + 1);
    	st.erase(temp);
    	}
    }
    return stringmax;
}
int main()
{
    set<string> st;
    string S = "";
    cin >> S;
    int res = maxUnique(S , st) ;
    cout<<res << endl;
}