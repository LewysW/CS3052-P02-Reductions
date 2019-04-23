#include "main.h"

/**
 * Main function
 * @param argc - number of arguments
 * @param argv - list of arguments
 * @return status code
 */
int main(int argc, char* argv[]) {
    if (argc > 1) {
        cout << "Usage:" << endl;
        cout << "./<path_to_executable> < <input_file>" << endl;
        cout << "Or alternatively, type input using standard input." << endl;
        return 0;
    }

    //Converts the first argument (the name of the executable) to string
    string execStr(argv[0]);

    //Returns the result of running the executable on the input
    return run(execStr);
}

/**
 * Runs the procedure corresponding to the name of the executable provided
 * @param execName - name of executable to run
 * @return status code of running executable
 */
int run(string execName) {
    int isValid = 0;

    //Runs if the 'sattothreesat' executable is provided
    if (endsWith(execName, "sattothreesat")) {
        ParserCNF parser;
        vector<string> file = parser.readInput();

        //Validates against malformed input
        if (file.empty()) {
            return EMPTY_FILE;
        } else if ((isValid = parser.validFile(file)) != 0) {
            return isValid;
        }

        //Creates a SAT object, initialised with the given file
        SAT sat(file);

        //Converts the SAT object to 3-SAT
        SAT threeSAT = *sat.to3SAT();

        //Prints the resulting object
        threeSAT.print();

        //Runs if the 'coltosat' executable is provided
    } else if (endsWith(execName, "coltosat")) {
        ParserCOL parser;
        vector<string> file = parser.readInput();

        //Validates against malformed input
        if (file.empty()) {
            return EMPTY_FILE;
        } else if ((isValid = parser.validFile(file)) != 0) {
            return isValid;
        }

        //Creates a COL object with the given input file
        COL col(file);

        //Converts COL object to SAT and prints it
        SAT sat = *col.toSAT();
        sat.print();

        //Runs if the 'threesattocol' executable is provided
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