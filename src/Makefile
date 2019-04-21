all: clean sattothreesat coltosat threesattocol

sattothreesat:
	g++ -Wall -Wextra main.cpp ./parsers/parserCNF.cpp ./parsers/parserCOL.cpp ./formats/SAT.cpp ./formats/clause.cpp ./formats/COL.cpp -o sattothreesat -std=c++11

coltosat:
	g++ -Wall -Wextra main.cpp ./parsers/parserCNF.cpp ./parsers/parserCOL.cpp ./formats/SAT.cpp ./formats/clause.cpp ./formats/COL.cpp -o coltosat -std=c++11

threesattocol:
	g++ -Wall -Wextra main.cpp ./parsers/parserCNF.cpp ./parsers/parserCOL.cpp ./formats/SAT.cpp ./formats/clause.cpp ./formats/COL.cpp -o threesattocol -std=c++11

clean: 
	rm -rf sattothreesat coltosat threesattocol *.o
