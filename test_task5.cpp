#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascal(int n);

int main() {

    // Test 1: n = 0
    vector<vector<int>> result0 = generatePascal(0);
    cout << "Test 1 - n = 0: ";
    cout << (result0.empty() ? "PASS" : "FAIL") << endl;

    // Test 2: n = 1
    vector<vector<int>> result1 = generatePascal(1);
    cout << "Test 2 - n = 1: ";
    cout << (result1.size() == 1 && result1[0] == vector<int>{1} ? "PASS" : "FAIL") << endl;

    // Test 3: n = 5
    vector<vector<int>> result5 = generatePascal(5);
    cout << "Test 3 - n = 5: ";
    cout << (result5.size() == 5 ? "PASS" : "FAIL") << endl;

    // Test 4: Verify row 5
    vector<int> expected = { 1, 4, 6, 4, 1 };

    cout << "Test 4 - Row 5: ";
    cout << (result5[4] == expected ? "PASS" : "FAIL") << endl;

    return 0;
}