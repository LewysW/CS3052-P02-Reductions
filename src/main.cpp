#include "main.h"


//TODO - remove comments before printing

int main(int argc, char* argv[]) {
    if (argc > 1) return 0;

    string execStr(argv[0]);
    return run(execStr);
}

int run(string execName) {
    int isValid = 0;

    if (endsWith(execName, "sattothreesat")) {
        ParserCNF parser;
        vector<string> file = parser.readInput();

        if (file.empty()) return EMPTY_FILE;

        if ((isValid = parser.validFile(file)) != 0) return isValid;

        SAT sat(file);
        SAT threeSAT = *sat.to3SAT();
        threeSAT.print();
    } else if (endsWith(execName, "coltosat")) {
        ParserCOL parser;
        vector<string> file = parser.readInput();

        if (file.empty()) return EMPTY_FILE;

        if ((isValid = parser.validFile(file)) != 0) return isValid;

        COL col(file);
        SAT sat = *col.toSAT();
        sat.print();

    } else if (endsWith(execName, "threesattocol")) {
        cout << "threesattocol" << endl;
        ParserCNF parser;
        vector<string> file = parser.readInput();

        if (file.empty()) return EMPTY_FILE;

        if ((isValid = parser.validFile(file)) != 0) return isValid;

        SAT sat(file);

        if (!sat.is3SAT()) return NOT_3SAT;
        
    }

    return isValid;
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