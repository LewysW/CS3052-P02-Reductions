# CS3052-P02-Reductions
Second practical for CS3052 Computational Complexity

Plan for practical:

SAT -> 3-SAT

3-SAT -> k-COL

k-COL -> SAT

Documents describe DIMACS format to use for practical

--------------------------------------------------

Task 1: Straightforward Reductions

Part 1:
SAT in DIMACS CNF format -> 3SAT DIMACS CNF format

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




































