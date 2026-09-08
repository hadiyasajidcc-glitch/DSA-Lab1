#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndices(const vector<int>& arr, int key);

int main() {

    // Test 1: Multiple occurrences
    vector<int> arr1 = { 2, 4, 2, 6, 2, 8 };
    vector<int> result1 = findAllIndices(arr1, 2);

    cout << "Test 1 - Multiple occurrences: ";
    for (int index : result1)
        cout << index << " ";
    cout << endl;

    // Test 2: Key not present
    vector<int> arr2 = { 1, 3, 5, 7 };
    vector<int> result2 = findAllIndices(arr2, 4);

    cout << "Test 2 - Key not present: ";
    cout << (result2.empty() ? "PASS" : "FAIL") << endl;

    // Test 3: Empty array
    vector<int> arr3;
    vector<int> result3 = findAllIndices(arr3, 5);

    cout << "Test 3 - Empty array: ";
    cout << (result3.empty() ? "PASS" : "FAIL") << endl;

    return 0;
}