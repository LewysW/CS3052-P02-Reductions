# CS3052-P02-Reductions
Second practical for CS3052 Computational Complexity

Compilation/Execution Instructions:

To compile the program executables, navigate to the 'src/' directory in the submission folder and run 'make' in a terminal.

To run the program(s), simply navigate to the 'src/' directory and run the following command:

	./<executable> < <input file>

The above command has the effect of running one of the provided executables and piping in a file as input.

To run the program using stacscheck, navigate to the 'src/' directory and run the following command:

	stacscheck Tests-v2-1



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

DIMACS COL format:

PREAMBLE - a series of lines beginning with a single character (c or p) to denote
a comment or problem line

	-Comments - Give human-readable information about the file and are ignored by programs,
		    occur at beginning of preamble

	-Problem line - There is one problem line per input file. Must appear before any node or arc descriptor lines. For CNF, has the following format:

			p FORMAT NODES EDGES

	
			FORMAT should contain the word "edge"

			NODES contains an integer specifying n, the number of nodes in the instance

			EDGES contains an integer specifying m, the number of EDGES in the instance

		The problem line should be the last line of the preamble

	-Colours line - Takes following format:
			COLOUR INTEGER

		Colour line should be first non-whitespace line after problem line

THE edges - format:
		e W V

		W is start point
		V is end point
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

	• ‘At-least-one’ clauses (ALO). A single clause {yi,1, yi,2, . . . yi,k} for each node i, which says that each node has
	to have at least one colour:

		i.e. if k is 4 then each node is assigned 4 unique colours (if there are 10 nodes then there will be 10 clauses, 1 for each colour)

	• ‘At-most-one’ clauses (AMO). A clause for every node and pair j, j0 of colours. The clause {¬yi,j , ¬yi,j0} says
	that node i can’t be both colour j and colour j'.

		i.e. generate a clause for each pair of colours in each node. For example if a node has 4 colours then 6 clauses are generated

	• ‘Edge’ clauses. For each edge in the graph connecting nodes i and i 0, one clause for each colour j. The clause {¬yi,j , ¬yi0,j} says that either i or i0 is not coloured with j (or neither is).
		
		i.e. for each colour i in the two nodes, make a clause made up of the two colours.

--------------------------------------------------

Task 2: More Complex Reduction

3SAT DIMACS CNF format -> kCOL DIMACS COL format

	Given k clauses and n >= 4 variables, we construct a graph with 3n + k vertices (nodes), e.g. in the case of n = 4, k = 4:

		{x1, ... ,xn} e.g. 1 - 4
		
		{¬x1, ..., ¬xn} e.g. 5 - 8

		{y1, ..., yn} e.g. 9 - 12

		{C1, ..., Ck} e.g. 13 - 16

	Edges given by rules:

		- Each vertex xi is joined to ¬xi e.g. {xi, ¬xi}

		- Each vertex yi is joined to every other yj e.g. {yi, yi + 1}, {yi, yi + 2}, ..., {yi, yi + n}, {yi + 1, yi + 2}, .... {yi + 1, yi + n}

		- Each vertex yi is joined to xj and ¬xj provided j != i e.g. {y1, x2}, {y1, ¬x2}, {y1, x3}, {y1, ¬x3} but not {y1, x1}, {y1, ¬x1}

		- Each vertex Ci is joined to each literal xj or ¬xj which is not in clause i e.g. if C1 = {x1, ¬x2}

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




































