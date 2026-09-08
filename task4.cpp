#include <string>
using namespace std;

int naiveSearch(const string& text, const string& pattern) {

    if (pattern.empty())
        return 0;

    if (pattern.length() > text.length())
        return -1;

    for (int i = 0; i <= (int)text.length() - (int)pattern.length(); i++) {

        int j = 0;

        while (j < (int)pattern.length() && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == (int)pattern.length())
            return i;
    }

    return -1;
}