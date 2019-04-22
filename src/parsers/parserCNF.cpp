#include "parserCNF.h"

/**
 * Reads in stdio file line by line
 * @return lines of file in string vector
 */
vector<string> ParserCNF::readInput() {
    string line;
    vector<string> lines;

    while (getline(cin, line)) {
        lines.push_back(line);
    }

    return lines;
}

/**
 * Validates a DIMACS SAT CNF file
 * @param file - to validate
 * @return 0 if file is valid or an error code if not
 */
int ParserCNF::validFile(vector<string>& file) {
    std::vector<string>::iterator pos;
    vector<string> line;

    //Iterate through comments
    for (auto it = file.begin(); it != file.end(); it++) {
        line = tokenizeLine(*it);

        if (line.empty()) continue;

        //Checks if line is not a comment
        if (it[0][0] == 'p') {
            pos = it;
            break;
        } else if (it[0][0] != 'c') {
            return INVALID_PREAMBLE;
        }
    }

    //Tokenizes problem line
    line = tokenizeLine(*pos);

    //Validates problem line
    if (line.size() != PROBLEM_LINE_LENGTH || line[0] != "p" || line[1] != "cnf") {
        return INVALID_PROBLEM_LINE;
    } else if (!is_digits(line[2] + line[3]) || stoi(line[2]) < 0 || stoi(line[3]) < 0) {
        return INVALID_PROBLEM_LINE;
    }

    int numVars = stoi(line[2]);
    int numClauses = stoi(line[3]);
    int clauseCount = 0;

    string clauses;
    for (auto it = pos + 1; it != file.end(); it++) {
        clauses += *it + " ";
    }

    line = tokenizeLine(clauses);
    int token = 0;

    for (auto it = line.begin(); it != line.end(); it++) {
        size_t numConverted;
        token = stoi(*it, &numConverted, BASE_TEN);

        if (numConverted != it->size() || (numConverted == it->size() && abs(token) > numVars)) {
            return INVALID_CLAUSES;
        } else if (token == 0) {
            clauseCount++;
        }
    }

    if (token != 0) numClauses++;

    //Validates against too few clauses
    if (clauseCount < numClauses || clauseCount > numClauses) return INVALID_CLAUSES;

    return 0;
}

/**
 * Tokenizes a line into a vector of strings
 * @param line - to tokenize
 * @return tokenized line
 */
vector<string> ParserCNF::tokenizeLine(string line) {
    vector<string> tokens;
    stringstream checkStream(line);
    string intermediate;

    while (getline(checkStream, intermediate, ' ')) {
        if (intermediate.find_first_not_of(' ') != std::string::npos) {
            tokens.push_back(intermediate);
        }
    }

    return tokens;
}

//https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits
bool ParserCNF::is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}