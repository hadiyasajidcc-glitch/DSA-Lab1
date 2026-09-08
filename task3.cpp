#include <iostream>
using namespace std;

int main() {
    int arr[] = { 2, 5, 2, 8, 2, 9 };
    int n = 6;
    int target = 2;

    cout << "Indices of " << target << ": ";

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}