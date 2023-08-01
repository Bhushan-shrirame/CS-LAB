#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void sortRows(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        sort(matrix[i].begin(), matrix[i].end());
    }
}

void sortColumns(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[j][i], matrix[n - 1 - j][i]);
        }
    }
}

bool isElementInMatrix(const vector<vector<int>>& matrix, int x) {
    int n = matrix.size();
    int row = 0;
    int col = n - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == x) {
            return true;
        } else if (matrix[row][col] < x) {
            row++;
        } else {
            col--;
        }
    }

    return false;
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            t.push_back(x);
        }
        matrix.push_back(t);
       
    }

    // Example usage:
    // vector<vector<int>> matrix = {
    //     {7, 6, 5},
    //     {4, 3, 2},
    //     {1, 0, -1}
    // };

    sortRows(matrix);
    sortColumns(matrix);
    
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
         cout << matrix [i][j] ;
    }
    cout << "\n" ;
    }

    int x = 2;
    bool is_element_present = isElementInMatrix(matrix, x);
    cout << boolalpha; // To print "true"/"false" 
    cout << is_element_present << endl;  // Output: true

    return 0;
}
