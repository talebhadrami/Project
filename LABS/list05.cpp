#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

// Function to input a square matrix
void inputMatrix(vector<vector<int>> &matrix, const string &name) {
    int n;
    cout << "Enter the order of matrix " << name << " (n x n): ";
    cin >> n;
    matrix.resize(n, vector<int>(n));
    cout << "Enter elements of matrix " << name << " (range [10, 100]): \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            do {
                cin >> matrix[i][j];
            } while (matrix[i][j] < 10 || matrix[i][j] > 100);
        }
    }
}

// Function to print a matrix
void printMatrix(const vector<vector<int>> &matrix, const string &name) {
    cout << "Matrix " << name << ":\n";
    for (const auto &row : matrix) {
        for (int elem : row) {
            cout << setw(5) << elem;
        }
        cout << endl;
    }
}

// Function to calculate row sums
vector<int> calculateRowSums(const vector<vector<int>> &matrix) {
    vector<int> rowSums(matrix.size(), 0);
    for (size_t i = 0; i < matrix.size(); ++i) {
        rowSums[i] = accumulate(matrix[i].begin(), matrix[i].end(), 0);
    }
    return rowSums;
}

// Function to calculate column sums
vector<int> calculateColumnSums(const vector<vector<int>> &matrix) {
    vector<int> colSums(matrix[0].size(), 0);
    for (size_t j = 0; j < matrix[0].size(); ++j) {
        for (size_t i = 0; i < matrix.size(); ++i) {
            colSums[j] += matrix[i][j];
        }
    }
    return colSums;
}

// Function to calculate the sum of transposed matrices
vector<vector<int>> calculateTransposeSum(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> S(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            S[i][j] = A[j][i] + B[j][i];
        }
    }
    return S;
}

// Function to add a row to a matrix at a specified position
void addRow(vector<vector<int>> &matrix, const vector<int> &row, int position) {
    if (position < 0 || position > matrix.size()) {
        cout << "Invalid position!" << endl;
        return;
    }
    matrix.insert(matrix.begin() + position, row);
}

// Function to add a column to a matrix at a specified position
void addColumn(vector<vector<int>> &matrix, const vector<int> &column, int position) {
    if (position < 0 || position > matrix[0].size()) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].insert(matrix[i].begin() + position, column[i]);
    }
}

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int rows = A.size(), cols = B[0].size(), inner = A[0].size();
    vector<vector<int>> P(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < inner; ++k) {
                P[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return P;
}

// Utility function to generate a random vector
vector<int> generateRandomVector(int n, int lower = 10, int upper = 100) {
    vector<int> vec(n);
    for (int &val : vec) {
        val = rand() % (upper - lower + 1) + lower;
    }
    return vec;
}

int main() {
    srand(time(0));

    // Input matrices
    vector<vector<int>> A, B;
    inputMatrix(A, "A");
    inputMatrix(B, "B");

    // Print matrices
    printMatrix(A, "A");
    printMatrix(B, "B");

    // Row sums
    vector<int> rowSumsA = calculateRowSums(A);
    vector<int> rowSumsB = calculateRowSums(B);
    cout << "Row sums of A: ";
    for (int sum : rowSumsA) cout << sum << " ";
    cout << endl;
    cout << "Row sums of B: ";
    for (int sum : rowSumsB) cout << sum << " ";
    cout << endl;

    // Column sums
    vector<int> colSumsA = calculateColumnSums(A);
    vector<int> colSumsB = calculateColumnSums(B);
    cout << "Column sums of A: ";
    for (int sum : colSumsA) cout << sum << " ";
    cout << endl;
    cout << "Column sums of B: ";
    for (int sum : colSumsB) cout << sum << " ";
    cout << endl;

    // Sum of transposed matrices
    vector<vector<int>> S = calculateTransposeSum(A, B);
    printMatrix(S, "S (Transpose Sum)");

    // Add a row to A
    vector<int> newRow = generateRandomVector(A[0].size());
    int rowPos;
    cout << "Enter position to add a row to A: ";
    cin >> rowPos;
    addRow(A, newRow, rowPos);
    printMatrix(A, "A (after adding row)");

    // Add a column to B
    vector<int> newCol = generateRandomVector(B.size());
    int colPos;
    cout << "Enter position to add a column to B: ";
    cin >> colPos;
    addColumn(B, newCol, colPos);
    printMatrix(B, "B (after adding column)");

    // Multiply matrices
    vector<vector<int>> P = multiplyMatrices(A, B);
    printMatrix(P, "P (Product of A and B)");

    return 0;
}
