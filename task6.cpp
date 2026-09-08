#include <vector>
#include <map>
using namespace std;

vector<int> findMode(const vector<int>& arr) {

    vector<int> modes;

    if (arr.empty())
        return modes;

    map<int, int> frequency;

    for (int value : arr) {
        frequency[value]++;
    }

    int maxFrequency = 0;

    for (auto item : frequency) {
        if (item.second > maxFrequency) {
            maxFrequency = item.second;
        }
    }

    for (auto item : frequency) {
        if (item.second == maxFrequency) {
            modes.push_back(item.first);
        }
    }

    return modes;
}