#include <vector>
using namespace std;

vector<vector<int>> addMatrix(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

vector<vector<int>> subtractMatrix(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

vector<vector<int>> strassen(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {
    int n = A.size();

    // Base case
    if (n == 1) {
        return { {A[0][0] * B[0][0]} };
    }

    int mid = n / 2;

    vector<vector<int>> A11(mid, vector<int>(mid));
    vector<vector<int>> A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid));
    vector<vector<int>> A22(mid, vector<int>(mid));

    vector<vector<int>> B11(mid, vector<int>(mid));
    vector<vector<int>> B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid));
    vector<vector<int>> B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    vector<vector<int>> M1 = strassen(
        addMatrix(A11, A22),
        addMatrix(B11, B22));

    vector<vector<int>> M2 = strassen(
        addMatrix(A21, A22),
        B11);

    vector<vector<int>> M3 = strassen(
        A11,
        subtractMatrix(B12, B22));

    vector<vector<int>> M4 = strassen(
        A22,
        subtractMatrix(B21, B11));

    vector<vector<int>> M5 = strassen(
        addMatrix(A11, A12),
        B22);

    vector<vector<int>> M6 = strassen(
        subtractMatrix(A21, A11),
        addMatrix(B11, B12));

    vector<vector<int>> M7 = strassen(
        subtractMatrix(A12, A22),
        addMatrix(B21, B22));

    vector<vector<int>> C11 = addMatrix(
        subtractMatrix(addMatrix(M1, M4), M5),
        M7);

    vector<vector<int>> C12 = addMatrix(M3, M5);

    vector<vector<int>> C21 = addMatrix(M2, M4);

    vector<vector<int>> C22 = addMatrix(
        subtractMatrix(addMatrix(M1, M3), M2),
        M6);

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

vector<vector<int>> standardMultiply(const vector<vector<int>>& A,
    const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}