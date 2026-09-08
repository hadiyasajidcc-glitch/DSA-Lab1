#include <iostream>
#include <string>
using namespace std;

int naiveSearch(const string& text, const string& pattern);

int main() {

    // Test 1: Pattern at the beginning
    cout << "Test 1 - Beginning: ";
    cout << (naiveSearch("hello world", "hello") == 0 ? "PASS" : "FAIL") << endl;

    // Test 2: Pattern at the end
    cout << "Test 2 - End: ";
    cout << (naiveSearch("hello world", "world") == 6 ? "PASS" : "FAIL") << endl;

    // Test 3: Pattern not present
    cout << "Test 3 - Not present: ";
    cout << (naiveSearch("hello world", "xyz") == -1 ? "PASS" : "FAIL") << endl;

    // Test 4: Empty pattern
    cout << "Test 4 - Empty pattern: ";
    cout << (naiveSearch("hello world", "") == 0 ? "PASS" : "FAIL") << endl;

    return 0;
}