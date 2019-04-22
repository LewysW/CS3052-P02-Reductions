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
        //Invalid if not a comment, the problem line, or an empty line
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

    //Stores the number of variables and clauses
    int numVars = stoi(line[2]);
    int numClauses = stoi(line[3]);

    int clauseCount = 0;

    //Concatenates the clauses into a single string
    string clauses;
    for (auto it = pos + 1; it != file.end(); it++) {
        clauses += *it + " ";
    }

    //Tokenizes the clauses into string tokens
    line = tokenizeLine(clauses);
    int token = 0;

    //Iterates through each token of the clauses
    for (auto it = line.begin(); it != line.end(); it++) {
        size_t numConverted;
        //Stores number of characters in token converted successfully by stoi()
        token = stoi(*it, &numConverted, BASE_TEN);

        //If the number converted was not correct for a positive or negative number (or was out of range)
        if (numConverted != it->size() || (numConverted == it->size() && abs(token) > numVars)) {
            //Return an error
            return INVALID_CLAUSES;
        //Otherwise if the token was successfully converted to a string and was 0
        } else if (token == 0) {
            //Increment number of clauses
            clauseCount++;
        }
    }

    //If the last token was not a 0, increment the number of clauses
    if (token != 0) numClauses++;

    //Validates against invalid number of clauses
    if (clauseCount != numClauses) return INVALID_CLAUSES;

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

    //Tokenizes a line by whitespace and pushes each token to a list of tokens
    while (getline(checkStream, intermediate, ' ')) {
        if (intermediate.find_first_not_of(' ') != std::string::npos) {
            tokens.push_back(intermediate);
        }
    }

    return tokens;
}


/**
 * Checks whether a string is made up of digits
 * Original source - https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits
 * @param str - to check for digits
 * @return - whether or not the string is digits
 */
bool ParserCNF::is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}