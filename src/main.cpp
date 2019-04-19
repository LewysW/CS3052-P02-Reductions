#include "main.h"
#include "SAT.h"

//TODO - remove comments before printing

int main(int argc, char* argv[]) {
    if (argc > 1) return 0;

    string execStr(argv[0]);
    int valid = 0;

    if (endsWith(execStr, "sattothreesat")) {
        ParserCNF parser;
        vector<string> file = parser.readInput();
        valid = parser.validFile(file);
        SAT sat(execStr);
        printFile(file);
    } else if (endsWith(execStr, "coltosat")) {
        cout << "coltosat" << endl;
    } else if (endsWith(execStr, "threesattocol")) {
        cout << "threesattocol" << endl;
    }

    return valid;
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

void printFile(vector<string>& file) {
    for (auto it = file.begin(); it != file.end(); it++) {
        cout << *it;
    }
}