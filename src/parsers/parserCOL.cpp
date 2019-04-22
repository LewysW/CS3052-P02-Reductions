#include "parserCOL.h"


/**
 * Reads in stdio file line by line
 * @return lines of file in string vector
 */
vector<string> ParserCOL::readInput() {
    string line;
    vector<string> lines;

    while (getline(cin, line)) {
        lines.push_back(line);
    }

    return lines;
}

/**
 * Validates a DIMACS COL file
 * @param file - to validate
 * @return 0 if file is valid or an error code if not
 */
int ParserCOL::validFile(vector<string>& file) {
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
    if (line.size() != PROBLEM_LINE_LENGTH || line[0] != "p" || line[1] != "edge") {
        return INVALID_PROBLEM_LINE;
    } else if (!is_digits(line[2] + line[3]) || stoi(line[2]) <= 0 || stoi(line[3]) <= 0) {
        return INVALID_PROBLEM_LINE;
    }

    int numNodes = stoi(line[2]);
    auto numEdges = (unsigned long) stoi(line[3]);

    //Validates colours line
    for (auto it = pos + 1; it != file.end(); it++) {
        line = tokenizeLine(*it);

        if (line.empty() || ((line.front() == "c") && line.front() != "colours")) continue;

        line = tokenizeLine(*it);

        //Checks if line is a valid colour line
        if (line.size() != NUM_COLOUR_TOKENS || line.front() != "colours" || !is_digits(line.back()) || line.back() == "0") {
            return INVALID_COLOURS;
        } else {
            pos = it;
            break;
        }
    }

    set<pair<int, int>> edges;

    //Validates edges
    for (auto it = pos + 1; it != file.end(); it++) {
        line = tokenizeLine(*it);
        //Continues to next line if nothing on line or a comment
        if (line.empty() || line.front() == "c") {
            continue;
        //Checks for an edge
        } else if ((line = tokenizeLine(*it)).front() == "e") {
            //Checks that edge is correct length and that second and third tokens are numbers
            if (line.size() != NUM_EDGE_TOKENS || (!is_digits(line[1] + line[2]))) {
                return INVALID_EDGES;
            //Checks if node values specified are in the correct range of 1 to n
            } else if (stoi(line[1]) == 0 || stoi(line[2]) == 0 || stoi(line[1]) > numNodes || stoi(line[2]) > numNodes) {
                return INVALID_EDGES;
            }

            //Makes pair of nodes (edge) and reverse edge
            auto edge = make_pair(stoi(line[1]), stoi(line[2]));
            auto edgeReverse = make_pair(stoi(line[2]), stoi(line[1]));

            //Checks that edges are not repeated
            if (edges.find(edge) != edges.end() || edges.find(edgeReverse) != edges.end()) {
                return INVALID_EDGES;
            } else {
                edges.insert(edge);
            }
        //Otherwise line is not valid
        } else {
            return INVALID_EDGES;
        }
    }

    //Checks if the number of edges is invalid
    if (edges.size() != numEdges) return INVALID_EDGES;

    return 0;
}

/**
 * Tokenizes a line into a vector of strings
 * @param line - to tokenize
 * @return tokenized line
 */
vector<string> ParserCOL::tokenizeLine(string line) {
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

/**
 * Checks whether a string is made up of digits
 * Original source - https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits
 * @param str - to check for digits
 * @return - whether or not the string is digits
 */
bool ParserCOL::is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}