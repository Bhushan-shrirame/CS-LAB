#include <bits/stdc++.h>
using namespace std;



// Structure to store row and column information
struct RowColInfo {
    int value;
    int row;
    int col;
};

// Function to construct M'
vector<vector<int>> constructMatrixM(vector<vector<int>>& M) {
    int n = M.size();
    
    // Initialize row and column arrays
    vector<RowColInfo> rowInfo(n);
    vector<RowColInfo> colInfo(n);
    
    for (int i = 0; i < n; ++i) {
        rowInfo[i].value = *min_element(M[i].begin(), M[i].end());
        rowInfo[i].row = i;
    }
    
    for (int j = 0; j < n; ++j) {
        vector<int> colValues;
        for (int i = 0; i < n; ++i) {
            colValues.push_back(M[i][j]);
        }
        auto maxElem = max_element(colValues.begin(), colValues.end());
        colInfo[j].value = *maxElem;
        colInfo[j].col = j;
    }
    
    // Sort row and column arrays
    sort(rowInfo.begin(), rowInfo.end(), [](const RowColInfo& a, const RowColInfo& b) {
        return a.value < b.value;
    });
    
    sort(colInfo.begin(), colInfo.end(), [](const RowColInfo& a, const RowColInfo& b) {
        return a.value > b.value;
    });
    
    // Construct M' based on sorted arrays
    vector<vector<int>> M_prime(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M_prime[rowInfo[i].row][colInfo[j].col] = M[i][j];
        }
    }
    
    return M_prime;
}

int main() {
    int n;
    cout << "Enter the size of the matrix M: ";
    cin >> n;
    
    vector<vector<int>> M(n, vector<int>(n));
    
    cout << "Enter the elements of the matrix M:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }
    
    vector<vector<int>> M_prime = constructMatrixM(M);
    
    cout << "Matrix M':" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << M_prime[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
