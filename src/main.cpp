#include "main.h"

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

        //Validates against malformed input
        if (file.empty()) {
            return EMPTY_FILE;
        } else if ((isValid = parser.validFile(file)) != 0) {
            return isValid;
        }

        SAT sat(file);
        SAT threeSAT = *sat.to3SAT();
        threeSAT.print();
    } else if (endsWith(execName, "coltosat")) {
        ParserCOL parser;
        vector<string> file = parser.readInput();

        //Validates against malformed input
        if (file.empty()) {
            return EMPTY_FILE;
        } else if ((isValid = parser.validFile(file)) != 0) {
            return isValid;
        }

        COL col(file);
        SAT sat = *col.toSAT();
        sat.print();

    } else if (endsWith(execName, "threesattocol")) {
        ParserCNF parser;
        vector<string> file = parser.readInput();

        //Validates against malformed input
        if (file.empty()) {
            return EMPTY_FILE;
        } else if ((isValid = parser.validFile(file)) != 0) {
            return isValid;
        }

        SAT sat(file);

        //Rejects if not in 3SAT
        if (!sat.is3SAT()) return NOT_3SAT;

        //Adds variables if there are less than 4
        if (sat.getNumVars() <= 3) sat.setNumVars(4);

        COL col = *sat.toKCOL();
        col.print();
    } else {
        return EXEC_NOT_RECOGNISED;
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