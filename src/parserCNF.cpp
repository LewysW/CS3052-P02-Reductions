//
// Created by locw on 19/04/19.
//

#include "parserCNF.h"
#include "SAT.h"

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
 * Validates a SAT CNF file
 * @param file - to validate
 * @return 0 if file is valid or an error code if not
 */
int ParserCNF::validFile(vector<string>& file) {
    std::vector<string>::iterator pos;
    vector<string> line;

    //Iterate through comments
    for (auto it = file.begin(); it != file.end(); it++) {
        if ((*it).empty()) continue;

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
    if (line.size() > PROBLEM_LINE_LENGTH || line.size() < PROBLEM_LINE_LENGTH) {
        return INVALID_PROBLEM_LINE;
    } else if (line[0] != "p") {
        return INVALID_PROBLEM_LINE;
    } else if (line[1] != "cnf") {
        return INVALID_PROBLEM_LINE;
    } else if (!is_digits(line[2]) || !is_digits(line[3])) {
        return INVALID_PROBLEM_LINE;
    }

    int numVars = stoi(line[2]);
    int numClauses = stoi(line[3]);
    int clauseCount = 0;

    //Iterates over each line of clauses
    for (auto it = pos + 1; it != file.end(); it++) {
        line = tokenizeLine(*it);

        //Iterates through each line in the series of clauses
        for (auto it1 = line.begin(); it1 != line.end(); it1++) {
            //Validates the number of variables
            if (!is_digits(*it1) || abs(stoi(*it1)) > numVars) {
                return INVALID_CLAUSES;
            } else if (*it1 == "0") {
                //Validates the number of clauses
                if (it != file.end() && it1 != line.end()) {
                    clauseCount++;

                    if (clauseCount > numClauses) return INVALID_CLAUSES;
                }
            }
        }
    }

    if (clauseCount < numClauses) return INVALID_CLAUSES;

    return 0;
}

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