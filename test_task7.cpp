#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<vector<int>> strassen(const vector<vector<int>>& A,
    const vector<vector<int>>& B);

vector<vector<int>> standardMultiply(const vector<vector<int>>& A,
    const vector<vector<int>>& B);

bool matricesEqual(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {
    if (A.size() != B.size())
        return false;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            if (A[i][j] != B[i][j])
                return false;
        }
    }

    return true;
}

int main() {

    // Test 1: 2x2 matrices
    vector<vector<int>> A2 = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B2 = {
        {5, 6},
        {7, 8}
    };

    vector<vector<int>> result2 = strassen(A2, B2);
    vector<vector<int>> expected2 = standardMultiply(A2, B2);

    cout << "Test 1 - 2x2 matrix: ";
    cout << (matricesEqual(result2, expected2) ? "PASS" : "FAIL") << endl;


    // Test 2: 4x4 matrices
    vector<vector<int>> A4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> B4 = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    vector<vector<int>> result4 = strassen(A4, B4);
    vector<vector<int>> expected4 = standardMultiply(A4, B4);

    cout << "Test 2 - 4x4 matrix: ";
    cout << (matricesEqual(result4, expected4) ? "PASS" : "FAIL") << endl;


    // Test 3: Random values
    vector<vector<int>> randomA(4, vector<int>(4));
    vector<vector<int>> randomB(4, vector<int>(4));

    srand(1);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            randomA[i][j] = rand() % 10;
            randomB[i][j] = rand() % 10;
        }
    }

    vector<vector<int>> randomResult = strassen(randomA, randomB);
    vector<vector<int>> randomExpected =
        standardMultiply(randomA, randomB);

    cout << "Test 3 - Random values: ";
    cout << (matricesEqual(randomResult, randomExpected) ? "PASS" : "FAIL") << endl;

    return 0;
}