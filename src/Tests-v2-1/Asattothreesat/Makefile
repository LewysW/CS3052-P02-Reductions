all: syntaxbad syntaxyes solutions nonsols

SYNTAXBAD=commentline1 commentline2 literal1 literal2 nopline1 nopline2 nopline3 clause1 clause2 clause3
SYNTAXYES=ok1 ok2 ok3 ok4 not3sat
SOLVABLE=1 4 10
UNSOLVABLE=1 2 3 4 10
SYNTAXBAD_FILES=${patsubst %,test-syntaxbad-%.sh,${SYNTAXBAD}}
SYNTAXYES_FILES=${patsubst %,test-syntaxyes-%.sh,${SYNTAXYES}}
SOLUTION_FILES=${patsubst %,test-solution-%.sh,${SOLVABLE}}
NONSOL_FILES=${patsubst %,test-unsolvable-%.sh,${UNSOLVABLE}}

test-syntaxbad-%.sh: syntaxbad-%.cnf
	echo "#!/bin/bash" > $@
	echo 'bash $${TESTDIR}/metatest-syntaxbad.sh $*' >> $@
	chmod a+x $@

syntaxbad: ${SYNTAXBAD_FILES}

test-syntaxyes-%.sh: syntaxyes-%.cnf
	echo "#!/bin/bash" > $@
	echo 'bash $${TESTDIR}/metatest-syntaxyes.sh $*' >> $@
	chmod a+x $@

syntaxyes: ${SYNTAXYES_FILES}

test-solution-%.sh: solution-%.cnf
	echo "#!/bin/bash" > $@
	echo 'bash $${TESTDIR}/metatest-solution.sh $*' >> $@
	chmod a+x $@

solutions: ${SOLUTION_FILES}

test-unsolvable-%.sh: unsolvable-%.cnf
	echo "#!/bin/bash" > $@
	echo 'bash $${TESTDIR}/metatest-unsolvable.sh $*' >> $@
	chmod a+x $@

nonsols: ${NONSOL_FILES}

