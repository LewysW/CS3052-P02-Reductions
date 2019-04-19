#include "main.h"

int main(int argc, char* argv[]) {
    if (argc > 1) return 0;
    cout << argv[0] << endl;
    string execStr(argv[0]);

    if (endsWith(execStr, "sattothreesat")) {
        cout << "sattothreesat" << endl;
    } else if (endsWith(execStr, "coltosat")) {
        cout << "coltosat" << endl;
    } else if (endsWith(execStr, "threesattocol")) {
        cout << "threesattocol" << endl;
    }

    return 0;
}

/**
 * Function to check whether a
 * string has a particular suffix
 * @param str - string to check
 * @param suffix - suffix to check for
 * @return - whether string has suffix
 *
 * source - //https://stackoverflow.com/questions/25777655/a-c-function-that-tests-if-the-c-string-ends-with-a-suffix
 */
bool endsWith(std::string str, std::string suffix) {
    if (str.length() < suffix.length())
        return false;

    return str.substr(str.length() - suffix.length()) == suffix;
}