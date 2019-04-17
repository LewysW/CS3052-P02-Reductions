# CS3052-P02-Reductions
Second practical for CS3052 Computational Complexity

Plan for practical:

SAT -> 3-SAT

3-SAT -> k-COL

k-COL -> SAT

--------------------------------------------------

Documents describe DIMACS format to use for practical

SAT CNF format:

PREAMBLE - a series of lines beginning with a single character (c or p) to denote
a comment or problem line

	-Comments - Give human-readable information about the file and are ignored by programs,
		    occur at beginning of preamble

	-Problem line - There is one problem line per input file. Must appear before any node or arc descriptor lines. For CNF, has the following format:

			p FORMAT VARIABLES CLAUSES

	
			FORMAT should contain the word "cnf"

			VARIABLES contains an integer specifying n, the number of variables in the instance

			CLAUSES contains an integer specifying m, the number of clauses in the instance

		The problem line should be the last line of the preamble

THE CLAUSES - Multiple lines, each clause is terminated by the value 0 (representing ∧).
	      Each variable is numbered from 1 to n. A negated variable is a negative number.
--------------------------------------------------

Task 1: Straightforward Reductions

Part 1:
SAT in DIMACS CNF format -> 3SAT DIMACS CNF format

To convert from SAT to 3SAT, iterate through the clauses while the clause is <= 3 literals in length. 
Once a fourth literal is encountered, split the clause in two (placing all literals beyond the first two into the second clause) and
introducing a new variable to the end of the first clause and the negation of that variable to the beginning of the second clause.
Repeat while there is a clause longer than three literals in length.

Source of above method: https://www.coursera.org/lecture/advanced-algorithms-and-complexity/sat-to-3-sat-S2Uvv

Part 2:
kCOL in DIMACS COL format -> SAT DIMACS CNF format

--------------------------------------------------

Task 2: More Complex Reduction

3SAT DIMACS CNF format -> kCOL DIMACS COL format

--------------------------------------------------

Task 3: Analysis and Circular Reductions

Analyse encodings to show they can run in polynomial time.

Analysis circular nature of encodings given input graph with n nodes

--------------------------------------------------

Task 4 (Extension): Reduction to 3-COL

4COL -> 3COL

Can use online solutions as long as these are cited

--------------------------------------------------

Stacscheck Tests:

Syntaxbad: not valid input files so program should return non-zero value

Syntaxyes: File is a valid input file and so the program returns a zero value

Solution: File is a valid instance and has a solution, so translated version should have a solution

Unsolvable: The file is a valid instance and has no solution, so translated version should have no solution




































