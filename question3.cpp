#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fori(n) for(int i=0; i<n; i++)

void inputVector(vector<int> &v, int n) {
    fori(n) {
        cin >> v[i];
    }
}

void printMatrix(vector<vector<int>> &v) {
    fori(v.size()) {
        for (int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    fori(n) {
        for (int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void multiplyMatrix(vector<vector<int>> &result, vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int n = matrix1.size();
    fori(n) {
        for (int j=0; j<n; j++) {
            result[i][j] = 0;
            for (int k=0; k<n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void solve() {
    cout<< "Enter size of matrix: ";
    int n;
    cin >> n;
    vector<vector<int>> matrix1(n, vector<int>(n));
    vector<vector<int>> matrix2(n, vector<int>(n));

    cout<< "Enter matrix 1: " << endl;
    fori(n) {
        inputVector(matrix1[i], n);
    }

    cout<< "Enter matrix 2: " << endl;
    fori(n) {
        inputVector(matrix2[i], n);
    }

    transposeMatrix(matrix1);
    transposeMatrix(matrix2);

    vector<vector<int>> result(n, vector<int>(n));
    multiplyMatrix(result, matrix1, matrix2);

    cout<< "Result: " << endl;
    printMatrix(result);
}

int main () {

    cout<< "Program to transpose and multiply two matrices" << endl;
    
    cout<< "Run test cases? (y/n): ";
    char c;
    cin >> c;

    if (c == 'y' || c == 'Y') {
        vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        vector<vector<int>> matrix2 = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
        int n = 3;
        vector<vector<int>> expected(n, vector<int>(n));
        vector<vector<int>> result = {{138, 174, 210}, {171, 216, 261}, {204, 258, 312}};

        transposeMatrix(matrix1);
        transposeMatrix(matrix2);
        multiplyMatrix(expected, matrix1, matrix2);
        fori(n) {
            for (int j=0; j<n; j++) {
                assert(result[i][j] == expected[i][j]);
            }
        }
        cout<< "All test cases passed" << endl;
    }

    cout<< "Run program using custom input? (y/n): ";
    cin >> c;

    if (c == 'y' || c == 'Y') {
        solve();
    }
    return true;
}