#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    class node
    {
        public:
        int data;
        int row;
        int col;

        node(int d, int r, int c)
        {
            data=d;
            row=r;
            col=c;
        }            
    };

    class compare
    {
        public:
        bool operator()(node*a, node*b)
        {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k=nums.size();
        priority_queue<node*, vector<node*>, compare> pq;
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=0;i<k;i++)
        {
            int element=nums[i][0];
            maxi=max(maxi, element);
            mini=min(mini, element);
            pq.push(new node(nums[i][0], i, 0));
        }

        int start=mini;
        int end=maxi;

        while(!pq.empty())
        {
            node* temp=pq.top();
            pq.pop();
            mini=temp->data;
            if(maxi-mini < end-start)
            {
                start=mini;
                end=maxi;
            }
            if(temp->col+1 < nums[temp->row].size())
            {
                maxi=max(maxi, nums[temp->row][temp->col+1]);
                pq.push(new node(nums[temp->row][temp->col+1], temp->row, temp->col+1));
            }
            else
            {
                break;
            }
        }
        
        cout << " The smallest range that includes at least one number from each of the lists: " << "{" << start << "," << end <<"}" << endl;

        return {start,end};
    }
};


int main() {

    Solution s;

    vector<vector<int>> v;
    int row, column, a;
    cin>>row;
    for(int i=0 ; i<row ; i++) {
         cin>>column;
         vector<int> p;
         for(int j=0 ; j<column ; j++) {
              cin>>a;
              p.push_back(a);
         }
         v.push_back(p);
    }
    s.smallestRange(v);
   return 0;
}