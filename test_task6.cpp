#include <iostream>
#include <vector>
using namespace std;

vector<int> findMode(const vector<int>& arr);

int main() {

    // Test 1: Unique mode
    vector<int> arr1 = { 1, 2, 2, 3, 4 };

    vector<int> result1 = findMode(arr1);

    cout << "Test 1 - Unique mode: ";
    cout << (result1.size() == 1 && result1[0] == 2 ? "PASS" : "FAIL") << endl;

    // Test 2: Multiple modes
    vector<int> arr2 = { 1, 1, 2, 2, 3 };

    vector<int> result2 = findMode(arr2);

    cout << "Test 2 - Multiple modes: ";

    if (result2.size() == 2 &&
        result2[0] == 1 &&
        result2[1] == 2) {
        cout << "PASS" << endl;
    }
    else {
        cout << "FAIL" << endl;
    }

    // Test 3: Empty array
    vector<int> arr3;

    vector<int> result3 = findMode(arr3);

    cout << "Test 3 - Empty array: ";
    cout << (result3.empty() ? "PASS" : "FAIL") << endl;

    return 0;
}